"""
CLI console utility copies files from subdirectories to these folders
for each folder in the parent directory.

## Usage example

Before:

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

After:

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

from pathlib import Path
import shutil


def all_files_to_parent_dir(path: str) -> None:
    for child_dir in Path(path).iterdir():
        for file in Path(child_dir).glob("**/*"):
            if file.is_file():
                file.replace(child_dir / file.name)
        for file in Path(child_dir).glob("**/*"):
            if file.is_dir():
                shutil.rmtree(file)
        print("Fix {}".format(child_dir))


if __name__ == "__main__":
    path = input()
    if path:
        all_files_to_parent_dir(path)
    else:
        all_files_to_parent_dir("D:\\Downloads\\_3d")
