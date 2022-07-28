"""
CLI console script removes the date from the names of folders, files and transfers
(for markdown files) it to YAML. Recursively.

Hidden folders and files are ignored.

`2022-04-16-test.md` to `test.md`.

## Usage example

With arguments:

```console
python date_from_filename_to_yaml.py C:/test/2022
```

Without arguments:

```console
python date_from_filename_to_yaml.py
C:/test/2022
n
.md
```

**Before:**

Folder structure:

```text
C:/test/2022
├─ 2022-04-16-test
│  ├─ 2022-04-16-test.en.md
│  ├─ 2022-04-16-test.md
│  ├─ featured-image.png
│  └─ img
│     └─ test.png
└─ 2022-04-17-test2
   ├─ 2022-04-17-test.md
   ├─ featured-image.png
   └─ img
      └─ test.png
```

File `C:/test/2022/2022-04-16-test/2022-04-16-test.en.md`:

```markdown
---
categories: [it, program]
---

# Test

![Test image](img/test.png)
```

**After:**

Folder structure:

```text
C:/test/2022
├─ test
│  ├─ featured-image.png
│  ├─ img
│  │  └─ test.png
│  ├─ test.en.md
│  └─ test.md
└─ test2
   ├─ featured-image.png
   ├─ img
   │  └─ test.png
   └─ test.md
```

File `C:/test/2022/test/test.en.md`:

```markdown
---
data: 2022-04-16
categories: [it, program]
---

# Test

![Test image](img/test.png)
```

## Using `--year`

```console
python date_from_filename_to_yaml.py C:/test/2022 --year
```

The parameter `--year` saves the year in the file name. If we apply the following
command for the example above, we get the following folder structure:

```text
C:/test/2022
├─ 2022-test
│  ├─ 2022-test.en.md
│  ├─ 2022-test.md
│  ├─ featured-image.png
│  └─ img
│     └─ test.png
└─ 2022-test2
   ├─ 2022-test.md
   ├─ featured-image.png
   └─ img
      └─ test.png
```

## Using `--ext`

Applies the date deletion operation in the file name only to files of the extension specified in the parameter `--ext`.

With arguments:

```console
python date_from_filename_to_yaml.py C:/test/2022 --ext .svg
```

Without arguments:

```console
python date_from_filename_to_yaml.py
C:/test/2022
n
.svg
```

**Before:**

```text
C:/test/2022
├─ 2022-04-16-test.svg
├─ 2022-05-09-test.svg
└─ 2022-05-09-test.png
```

**After:**

```text
C:/test/2022
├─ test.svg
├─ test.svg
└─ 2022-05-09-test.png
```

## Using `--ext` and `--year`

```console
python date_from_filename_to_yaml.py C:/test/2022 --year --ext .svg
```

Command get the following folder structure for the example above:

```text
C:/test/2022
├─ 2022-test.svg
├─ 2022-test.svg
└─ 2022-05-09-test.png
```
"""
import argparse
import os
import re
from pathlib import Path
from typing import Union

DEFAULT_EXTENSION = ".md"


def date_from_filename_to_yaml(
    path: Union[Path, str], is_save_year=False, ext=DEFAULT_EXTENSION
) -> None:
    """
    This function removes the date from the names of folders, files and transfers
    (for Markdown files) it to YAML. Recursively. `2022-04-16-test.md` to `test.md`.

    Args:

    - `path` (Path | str): Path to the directory being checked.
    - `is_save_year` (bool): Saves the year in the file name. Defaults to `False`.
    - `ext` (str):  Applies the date deletion operation in the file name only to files of the extension. Defaults to `.md`.

    Returns:

    - `None`.
    """
    for item in filter(
        lambda path: not any((part for part in path.parts if part.startswith("."))),
        Path(path).rglob("*"),
    ):
        if item.is_file():
            __rename_file(item, is_save_year, ext)

    for item in filter(
        lambda path: not any((part for part in path.parts if part.startswith("."))),
        Path(path).rglob("*"),
    ):
        if item.is_dir():
            __rename_dir(item, is_save_year)


def __get_pattern(is_save_year, ext=DEFAULT_EXTENSION):
    return r"^(\d{4})-(\d{2}-\d{2})-(.*)" + ext + r"$"


def __get_new_filename(res, is_save_year, ext=DEFAULT_EXTENSION) -> str:
    if not is_save_year:
        return f"{res.group(3)}{ext}"
    else:
        return f"{res.group(1)}-{res.group(3)}{ext}"


def __rename_file(file: Path, is_save_year, ext=DEFAULT_EXTENSION) -> None:
    pattern = __get_pattern(is_save_year, ext)
    res = re.match(pattern, file.name)
    if not bool(res):
        return

    if ext.lower() == DEFAULT_EXTENSION:
        content = file.read_text(encoding="utf8")
        if content.count("---") >= 2:
            lines = content.splitlines()
            lines[0] = f"---\ndate: {res.group(1)}-{res.group(2)}"
            file.write_text("\n".join(lines) + "\n", encoding="utf8")

    new_filename = __get_new_filename(res, is_save_year, ext)
    try:
        os.rename(file.parent / file.name, file.parent / new_filename)
        print(f"File '{file.parent / file.name}' renamed.")
    except FileExistsError as exception:
        print(exception)


def __rename_dir(dir: Path, is_save_year) -> None:
    pattern = __get_pattern(is_save_year, ext=r"")
    res = re.match(pattern, dir.name)
    if not bool(res):
        return

    new_filename = __get_new_filename(res, is_save_year, ext="")
    try:
        os.rename(dir.parent / dir.name, dir.parent / new_filename)
        print(f"Dir '{dir.parent / dir.name}' renamed.")
    except Exception as exception:
        print(exception)


def main():
    parser = argparse.ArgumentParser(
        description="Remove the date from the names of folders and markdown files "
        "and transfers it to yaml. See docstring for more information."
    )
    parser.add_argument(
        "path",
        type=str,
        nargs="?",
        help="path of the folder with markdown files",
    )
    parser.add_argument("--year", action="store_true", help="save year in filenames")
    parser.add_argument("--ext", default=DEFAULT_EXTENSION, help="ext of filenames")

    args = parser.parse_args()
    if args.path is not None and Path(args.path).is_dir():
        ext = DEFAULT_EXTENSION if args.ext is None else args.ext
        date_from_filename_to_yaml(args.path, args.year, ext)
    else:
        path = input("Input path: ")
        year = input("Save the year in filenames (y/n): ")
        ext = input("Input the file extension (default: .md): ")
        ext = DEFAULT_EXTENSION if not bool(ext) else ext
        if "." not in ext:
            print("Invalid the file extension.")
            return
        is_save_year = True if year.lower().startswith("y") else False
        if Path(path).is_dir():
            date_from_filename_to_yaml(path, is_save_year, ext)
        else:
            print("Invalid path.")


if __name__ == "__main__":
    main()
