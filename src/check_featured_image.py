"""
CLI console script check files `featured_image.*` in every child directory.
Not recursively.

## Usage example

With arguments:

```console
python check_featured_image.py C:/test
```

Without arguments:

```console
python check_featured_image.py
C:/test
```

For this situation:

```text
C:\test
├─ note1
│  ├─ featured-image.png
│  └─ note1.md
└─ note2
   └─ note2.md
```

Result: `C:\test\note2 without featured-image`

For this situation:

```text
C:\test
├─ note1
│  ├─ featured-image.png
│  └─ note1.md
└─ note2
   ├─ featured-image.png
   └─ note2.md
```

Result: `All correct in C:\test`

"""

import argparse
from pathlib import Path


def check_featured_image(path: str) -> None:
    """
    This function check files `featured_image.*` in every child directory.
    Not recursively.

    Args:

    - `path` (Path | str): Path to the directory being checked.

    Returns:

    - `bool`. True if each child folder contains `featured_image.*`, False otherwise.
    """
    is_correct = True

    for child_dir in Path(path).iterdir():
        is_featured_image = False
        for file in Path(child_dir).iterdir():
            if file.is_file() and file.name.startswith("featured-image"):
                is_featured_image = True
        if not is_featured_image:
            is_correct = False
            print("\x1b[31m{} without featured-image\x1b[0m".format(child_dir))

    if is_correct:
        print("All correct in {}".format(path))
    return is_correct


def main():
    parser = argparse.ArgumentParser(
        description="Check files `featured_image.*` in every child directory."
    )
    parser.add_argument(
        "path",
        type=str,
        nargs="?",
        help="path of the folder",
    )

    args = parser.parse_args()
    if args.path is not None and Path(args.path).is_dir():
        check_featured_image(args.path)
    else:
        path = input("Input path: ")
        if not path.strip():
            lst = [
                "D:\\Dropbox\\IT\\3D printer\\Models\\Print",
                "D:\\Dropbox\\IT\\3D printer\\Models\\Printed",
                "D:\\Dropbox\\IT\\3D printer\\Models\\Unprinted",
                "D:\\Dropbox\\IT\\3D printer\\Models - Box\\Printed",
                "D:\\Dropbox\\IT\\3D printer\\Models - Box\\Unprinted",
                "D:\\Dropbox\\IT\\3D printer\\Models - Cable\\Printed",
                "D:\\Dropbox\\IT\\3D printer\\Models - Cable\\Unprinted",
                "D:\\Dropbox\\IT\\3D printer\\Models - Miscellaneous\\Print",
                "D:\\Dropbox\\IT\\3D printer\\Models - Miscellaneous\\Printed",
                "D:\\Dropbox\\IT\\3D printer\\Models - Miscellaneous\\Unprinted",
                "D:\\Dropbox\\IT\\3D printer\\Models - Puzzle\\Bad",
                "D:\\Dropbox\\IT\\3D printer\\Models - Puzzle\\Printed",
                "D:\\Dropbox\\IT\\3D printer\\Models - Puzzle\\Unprinted",
                "D:\\Dropbox\\IT\\3D printer\\Models - Science\\Printed",
                "D:\\Dropbox\\IT\\3D printer\\Models - Science\\Unprinted",
            ]
            for path in lst:
                check_featured_image(path)
        elif Path(path).is_dir():
            check_featured_image(path)
        else:
            print("Invalid path.")


if __name__ == "__main__":
    main()
