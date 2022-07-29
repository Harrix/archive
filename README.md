# Harrix PyUtilities

**English** | [Russian](https://github.com/Harrix/harrix-pyutilities/blob/main/README.ru.md)

![Harrix PyUtilities](img/featured-image.svg)

Python utilities for solving various tasks.

All utilities are independent and unrelated to each other.

## Universal

The package [argparse](https://docs.python.org/3/library/argparse.html) is used.

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

- [check_featured_image.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/check_featured_image.py): CLI console script checks `featured_image` in every child directory. Not recursively.

- [date_from_filename_to_yaml.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/date_from_filename_to_yaml.py): CLI console script removes the date from the names of folders and markdown (and other) files and transfers (for markdown files) it to YAML. Before: `2022-04-16-test.md`. After: `test.md`. Recursively.

- [tree_folder.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/tree_folder.py): CLI console script builds a tree of files and subdirectories of the specified directory.

  <details>
  <summary>Example output</summary>

  ```text
  ├─ note1
  │  ├─ featured-image.png
  │  └─ note1.md
  └─ note2
     └─ note2.md
  ```

  </details>

## Specific

These utilities are made for my specific tasks. The package `argparse` is not used.

- [check_featured_image.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/specific__field_list_analysis.py): The script analyzes a field list from Markdown.

  <details>
  <summary>Example of a field list</summary>

  ```markdown
  # Title

  ---

  **Title of the field list** <!-- !list-as-table -->

  <!-- !item -->

  - **Field1:** Name1
  - **Field2:** One Two
  - **Field3:** 1

  <!-- !item -->

  - **Field1:** Name2
  - **Field2:** Three Four
  - **Field3:** 2

  ---
  ```

  </details>
