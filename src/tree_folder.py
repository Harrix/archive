"""
TODO
"""

"""
CLI console script removes the date from the names of folders and markdown
(and other) files and transfers (for markdown files) it to YAML.

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

```md
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

```md
---
data: 2022-04-16
categories: [it, program]
---

# Test

![Test image](img/test.png)
```

## Using `--year`

```console
`python date_from_filename_to_yaml.py C:/test/2022 --year`
```

If we apply the following command for the example above, we get the following
folder structure:

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
from pathlib import Path
from typing import Union


def tree(path: Union[Path, str], is_ignore_hidden_dirs=False) -> str:
    def __tree(path: Path, is_ignore_hidden_dirs=False, prefix: str = "") -> str:
        if is_ignore_hidden_dirs and path.name.startswith("."):
            contents = []
        else:
            try:
                contents = list(path.iterdir())
            except PermissionError:
                contents = []
        pointers = ["├─ "] * (len(contents) - 1) + ["└─ "]
        for pointer, path in zip(pointers, contents):
            yield prefix + pointer + path.name
            if path.is_dir():
                extension = "│  " if pointer == "├─ " else "   "
                yield from __tree(
                    path, is_ignore_hidden_dirs, prefix=prefix + extension
                )

    return "\n".join([line for line in __tree(Path(path), is_ignore_hidden_dirs)])


def main():
    parser = argparse.ArgumentParser(
        description="Display a tree of files and directories in the directory."
    )
    parser.add_argument(
        "path",
        type=str,
        nargs="?",
        help="path of the folder",
    )

    parser.add_argument(
        "--ignore",
        action="store_true",
        help="ignore the contents of hidden folders whose names start with a dot",
    )

    args = parser.parse_args()
    if args.path is not None and Path(args.path).is_dir():
        print(tree(args.path, args.ignore))
    else:
        path = input("Input path: ")
        ignore = input("Ignore the contents of hidden folders (y/n): ")
        is_ignore_hidden_dirs = True if ignore.lower().startswith("y") else False
        if Path(path).is_dir():
            print(tree(path, is_ignore_hidden_dirs))
        else:
            print("Invalid path.")


if __name__ == "__main__":
    main()
