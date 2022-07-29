"""
The script analyzes a field list from Markdown.

## Usage example

```console
python field_list_analysis.py
data/table.md
Field1, Field2
```

Example of Markdown file with a field list:

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

Output:

```console
Input path: data/table.md
Input fields (example: field1, field2): Field1, Field2
Count: 2:
- Name1 - One Two
- Name2 - Three Four
```
"""
import re
from pathlib import Path


class FieldList:
    """
    The class works with a field list from Markdown and parses it.

    Attributes:

    - `title` (str): Title of the field list.
      Example: `Title of the field list`.
    - `items` (list[dict]): The List of items from the filed list. Example:
      ```python
      [
          {"Field1": "Name1", "Field2": "One Two", "Field3": "1"},
          {"Field1": "Name2", "Field2": "Three Four", "Field3": "2"},
      ]
      ```

    Example of Markdown file contents:

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

    Text.
    ```

    Usage example:

    ```python
    >>> table = FieldList().load_first_from_file("data/table.md")
    >>> print("Count: {}:".format(len(table)))
    >>> print(
    >>>     table.get_md_list(["Field1", "Field3"], template="{} - {}")
    >>> )
    >>> for key, value in table[0].items():
    >>>     print("{}, {}".format(key, value))

    Count: 2:
    - Name1 - 1
    - Name2 - 2

    Field1, Name1
    Field2, One Two
    Field3, 1
    ```
    """

    def __init__(self) -> None:
        self.markdown = ""
        self.title = ""
        self.items = []
        self._REGEXP = (
            r"---\n\n\*\*(.*?)\*\* <!-- !list-as-table -->\n\n([\s\S]*?)\n\n---"
        )

    def load_first_from_file(self, filename: str):
        """
        The method pulls the first field list from the Markdown file.

        Args:

        - `filename`: The filename of a Markdown file.

        Returns:

        - `self`.
        """
        with open(filename, encoding="utf-8") as f:
            content = f.read()
            find = re.search(self._REGEXP, content, re.DOTALL)
            if not find:
                return self
            self.markdown = find.group()
            self._parse_field_list()
        return self

    def get_md_list(self, fields, template=""):
        """
        Args:

        - `fields` (list[str]): The list of fields to display in the list.
          Example: `["Name", "Rating"]`.
        - `template` (str): The template for output. Example `- {} (Rating: {})`.

        Returns:

        - `str`: Markdown list of items from the field list.

        ```python
        >>> table = FieldList().load_first_from_file("data/table.md")
        >>> print(
        >>>     table.get_md_list(["Field1", "Field3"], template="{} - {}")
        >>> )
        - Name1 - 1
        - Name2 - 2
        ```
        """
        res = ""
        if not template:
            template = " - ".join(["{}"] * len(fields))
        for item in self.items:
            lst_for_line = []
            for field in fields:
                if field in item:
                    lst_for_line.append(item[field])
                else:
                    lst_for_line.append("")
            res += "- " + template.format(*lst_for_line) + "\n"
        return res

    def _parse_field_list(self, markdown=""):
        if markdown:
            self.markdown = markdown
        find = re.search(self._REGEXP, self.markdown, re.DOTALL)
        if not find:
            return
        self.title = find.group(1)
        items = list(
            map(str.strip, filter(None, find.group(2).split("<!-- !item -->")))
        )
        for row in items:
            item = dict()
            fields = row.split("\n")
            for field in fields:
                try:
                    key, value = re.findall(r"^- \*\*(.*?):\*\* (.*?)$", field)[0]
                except:
                    try:
                        key = re.findall(r"^- \*\*(.*?):\*\*$", field)[0]
                        value = ""
                    except:
                        print("\x1b[31mProblems with line: {}\x1b[0m".format(field))
                item[key] = value
            self.items.append(item)

    def __len__(self):
        return len(self.items)

    def __getitem__(self, index):
        return self.items[index]


def main():
    path = input("Input path: ")
    if path:
        if not Path(path).is_file():
            print("Invalid path.")
            return
        table = FieldList().load_first_from_file(path)
        fields = list(
            map(
                str.strip,
                input("Input fields (example: field1, field2): ").split(","),
            )
        )
        print("Count: {}:".format(len(table)))
        print(table.get_md_list(fields))
        return

    table_books = FieldList().load_first_from_file("data/books.md")
    print("Книги (количество: {}):".format(len(table_books)))
    print(
        table_books.get_md_list(["Name", "Author", "Rating"], template="{} ({}) - {}")
    )
    print()
    table_movies = FieldList().load_first_from_file("data/movies.md")
    print("Фильмы (количество: {}):".format(len(table_movies)))
    print(
        table_movies.get_md_list(
            ["Name", "Season", "Rating"], template="{} (Сезон {}) - {}"
        ).replace("(Сезон ) ", "")
    )


if __name__ == "__main__":
    main()
