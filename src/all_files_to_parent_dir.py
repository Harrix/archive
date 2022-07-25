"""
CLI console script for each directory located directly in the specified directory moves
all files from subdirectories (recursively) to these directories. See the example below.

## Usage example

With arguments:

```console
python all_files_to_parent_dir.py C:/test
```

Without arguments:

```console
python all_files_to_parent_dir.py
C:/test
```

**Before:**

```text
C:\test
├─ folder1
│  ├─ image.jpg
│  ├─ sub1
│  │  ├─ file1.txt
│  │  └─ file2.txt
│  └─ sub2
│     ├─ file3.txt
│     └─ file4.txt
└─ folder2
   └─ sub3
      ├─ file6.txt
      └─ sub4
         └─ file5.txt
```

**After:**

```text
C:\test
├─ folder1
│  ├─ file1.txt
│  ├─ file2.txt
│  ├─ file3.txt
│  ├─ file4.txt
│  └─ image.jpg
└─ folder2
   ├─ file5.txt
   └─ file6.txt
```

"""

import argparse
import shutil
from pathlib import Path

DEFAULT_PATH = "D:\\Downloads\\_3d"


def all_files_to_parent_dir(path: Path | str) -> None:
    """
    This function check files `featured_image.*` in every child directory.
    Not recursively.

    Args:

    - `path` (Path | str): Path to the directory being checked.

    Returns:

    - `bool`: True if each child folder contains `featured_image.*`, False otherwise.
    """
    for child_dir in Path(path).iterdir():
        for file in Path(child_dir).glob("**/*"):
            if file.is_file():
                try:
                    file.replace(child_dir / file.name)
                except Exception as exception:
                    print(exception)
        for file in Path(child_dir).glob("**/*"):
            if file.is_dir():
                try:
                    shutil.rmtree(file)
                except Exception as exception:
                    print(exception)
        print("Fix {}".format(child_dir))


def main():
    parser = argparse.ArgumentParser(
        description="Copies files from subdirectories to these folders "
        "for each folder in the parent directory."
    )
    parser.add_argument(
        "path",
        type=str,
        nargs="?",
        help="path of the folder",
    )

    args = parser.parse_args()
    if args.path is not None and Path(args.path).is_dir():
        all_files_to_parent_dir(args.path)
    else:
        path = input("Input path: ")
        path = DEFAULT_PATH if not bool(path) else path
        if Path(path).is_dir():
            all_files_to_parent_dir(path)
        else:
            print("Invalid path.")


if __name__ == "__main__":
    main()
