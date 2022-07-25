# Harrix PyUtilities

[English](https://github.com/Harrix/harrix-pyutilities/) | **Russian**

Python утилиты для решения различных задач.

Все утилиты независимы и не связаны друг с другом.

- [all_files_to_parent_dir](https://github.com/Harrix/harrix-pyutilities/blob/main/src/all_files_to_parent_dir.py): Для
  каждой директории, которые находятся непосредственно в указанной директории (рекурсивно), перемещает все файлы из поддиректорий в эти самые директории. Было: `C:\test\folder1\sub1\file1.txt`. Стало: `C:\test\folder1\file1.txt`.

    <details>
    <summary>Пример</summary>

  **Было:**

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

  **Стало:**

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

- [check_featured_image.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/check_featured_image.py): Проверяет наличие файла `featured_image.*` во всех дочерних директориях (не рекурсивно) указанной директории.

- [date_from_filename_to_yaml.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/date_from_filename_to_yaml.py): Удаляет дату из имен директорий, файлов и переносит дату (для Markdown файлов) в YAML. Было: `2022-04-16-test.md`. Стало: `test.md`. Рекурсивно.

- [tree_folder.py](https://github.com/Harrix/harrix-pyutilities/blob/main/src/tree_folder.py): Строит дерево файлов и поддиректорий указанной директории.

  <details>
  <summary>Пример вывода</summary>

  ```text
  ├─ note1
  │  ├─ featured-image.png
  │  └─ note1.md
  └─ note2
     └─ note2.md
  ```

  </details>
