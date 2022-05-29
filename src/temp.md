# Temp title

CLI console script displays a tree of files and directories in the directory.

The contents of hidden folders (the name starts with a dot) can be hidden (`--ignore`).

## Usage example

With arguments:

```console
python tree_folder.py C:/test/
```

Without arguments:

```console
python tree_folder.py
C:/test/2022
n
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
`python tree_folder.py C:/test/2022 --year`
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
python tree_folder.py C:/test/2022 --ext .svg
```

Without arguments:

```console
python tree_folder.py
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
python tree_folder.py C:/test/2022 --year --ext .svg
```

Command get the following folder structure for the example above:

```text
C:/test/2022
├─ 2022-test.svg
├─ 2022-test.svg
└─ 2022-05-09-test.png
```
