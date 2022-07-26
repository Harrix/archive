"""
CLI console script analyzes the field list from Markdown.

## Usage example

With arguments:

```console
python field_list_analysis.py data/table.md
```

Without arguments:

```console
python field_list_analysis.py
data/table.md
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
"""
import argparse
import re
from pathlib import Path


class FieldList:
    def __init__(self) -> None:
        self.markdown = ""
        self.title = ""
        self.items = []
        self.REGEXP = (
            r"---\n\n\*\*(.*?)\*\* <!-- !list-as-table -->\n\n([\s\S]*?)\n\n---"
        )

    def load_first_from_file(self, filename):
        with open(filename, encoding="utf-8") as f:
            content = f.read()
            find = re.search(self.REGEXP, content, re.DOTALL)
            if not find:
                return self
            self.markdown = find.group()
            self.parse_field_list()
        return self

    def parse_field_list(self, markdown=""):
        if markdown:
            self.markdown = markdown
        find = re.search(self.REGEXP, self.markdown, re.DOTALL)
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

    def get_md_list(self, fields, template=""):
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


def main():
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
