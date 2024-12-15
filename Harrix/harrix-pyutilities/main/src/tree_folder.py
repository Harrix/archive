"""
CLI console script builds a tree of files and subdirectories of the specified directory.

## Usage example

With arguments:

```console
python check_featured_image.py C:/test
```

With arguments and ignoring hidden files:

```console
python check_featured_image.py C:/test --ignore
```

Without arguments:

```console
python check_featured_image.py
C:/test
y
```

Example output:

```text
├─ note1
│  ├─ featured-image.png
│  └─ note1.md
└─ note2
   └─ note2.md
```
"""
import argparse
from pathlib import Path


def tree(path: Path | str, is_ignore_hidden_dirs=False) -> str:
    """
    This function builds a tree of files and subdirectories of the specified directory.

    Args:

    - `path` (Path | str): Path to the directory.
    - `is_ignore_hidden_dirs` (bool): Ignores files and folders starting with a dot
       (for example `.git`). Defaults to `False`.

    Returns:

    - `str`: tree of files and subdirectories.
    """

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
