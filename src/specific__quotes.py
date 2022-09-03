"""
Scripts for the design of Markdown quotes.

## Usage example

```console
python specific__quotes.py
D:/Dropbox/Notes/Quotes/Fiction
```

For a description of the functions, see the docstring of the functions.
"""
from pathlib import Path


def add_author_book(filename: Path | str) -> None:
    """
    The function adds the author and the title of the book to the quotes and forms them
    as Markdown quotes.

    Args:

    - `filename` (Path | str): The filename of the Markdown File.

    Returns:

    - `None`.

    Example file `C:/test/Name_Surname/Title_of_book/Title_of_book.md`:

    ```markdown
    # Title of book

    Line 1.

    Line 2.

    ---

    Line 3.

    Line 4.

    -- Modified title of book
    ```

    After:

    ```markdown
    # Title of book

    > Line 1.
    >
    > Line 2.
    >
    > _Name Surname - Title of book_

    ---

    > Line 3.
    >
    > Line 4.
    >
    > _Name Surname - Modified title of book_
    ```
    """
    file = Path(filename)
    if not file.is_file():
        return
    if file.suffix.lower() != ".md":
        return
    note_initial = file.read_text(encoding="utf8")
    lines = note_initial.splitlines()

    author = file.parts[-3].replace("-", " ")
    title = lines[0].replace("# ", "")

    lines = lines[1:-1] if lines[-1].strip() == "---" else lines[1:]
    note = f"# {title}\n\n"
    quotes = list(map(str.strip, filter(None, "\n".join(lines).split("\n---\n"))))

    quotes_fix = []
    for quote in quotes:
        lines_quote = quote.splitlines()
        if lines_quote[-1].startswith("> -- _"):
            quotes_fix.append(quote)  # The quote has already been processed
            continue
        if lines_quote[-1].startswith("-- "):
            title = lines_quote[-1][3:]
            del lines_quote[-2:]
        quote_fix = "\n".join([f"> {line}".rstrip() for line in lines_quote])
        quotes_fix.append(f"{quote_fix}\n>\n> -- _{author}, {title}_")
    note += "\n\n---\n\n".join(quotes_fix) + "\n"
    if note_initial != note:
        file.write_text(note, encoding="utf8")
        print(f"\x1b[34mFix {filename}\x1b[0m")
    else:
        print(f"No changes in {filename}")


def modify_all_md_in_folder(path: Path | str, fn) -> None:
    """
    The function applies the function `add_author_book` to all Markdown files
    in the folder.

    Args:

    - `path` (Path | str): The path to the directory being processed.
    - `fn`: The function that processes a Markdown file.

    Returns:

    - `None`.
    """
    for item in filter(
        lambda path: not any((part for part in path.parts if part.startswith("."))),
        Path(path).rglob("*"),
    ):
        if item.suffix.lower() == ".md":
            fn(item)


def main():
    path = input("Input path: ")
    if Path(path).is_dir():
        modify_all_md_in_folder(path, add_author_book)
    else:
        print("Invalid path.")


if __name__ == "__main__":
    main()
