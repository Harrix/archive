# Harrix PyUtilities

**English** | [Russian](https://github.com/Harrix/harrix-pyutilities/blob/main/README.ru.md)

Python utilities for solving various tasks.

All utilities are independent and unrelated to each other.

- [all_files_to_parent_dir](https://github.com/Harrix/harrix-pyutilities/blob/main/src/all_files_to_parent_dir.py): CLI console script copies files from subdirectories (recursively) to these folders for each folder in the parent directory. Before: `C:\test\folder1\sub1\file1.txt`. After: `C:\test\folder1\file1.txt`.

  <details>
  <summary>Example</summary>

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

  </details>

- [date_from_filename_to_yaml.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/date_from_filename_to_yaml.py): CLI console script removes the date from the names of folders and markdown (and other) files and transfers (for markdown files) it to YAML. Before: `2022-04-16-test.md`. After: `test.md`. Recursively.
