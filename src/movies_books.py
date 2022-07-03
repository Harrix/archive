"""
TODO
"""

import re
from pathlib import Path


def table_analysis(name, filename):
    file = Path(filename)
    with open(file, encoding="utf-8") as f:
        content = f.read().split("<!-- !item -->")
    table = []
    for item in content:
        item = item.strip().splitlines()
        if len(item) == 0:
            continue
        row = dict()
        for s in item:
            result = re.findall(r"^- \*\*(.*?):\*\* (.*?)$", s)
            if len(result) > 0:
                row[result[0][0]] = result[0][1]
        table.append(row)

    print("{} (количество: {}):\n".format(name, len(table)))
    for row in table:
        if "Season" in row:
            print("- {} (Сезон {}) - {}".format(row["Name"], row["Season"], row["Rating"]))
        elif "Author" in row:
            print("- {} ({}) - {}".format(row["Name"], row["Author"], row["Rating"]))
        else:
            print("- {} - {}".format(row["Name"], row["Rating"]))


# table_analysis("Фильмы", "data/movies.txt")
# print()
# table_analysis("Книги", "data/books.txt")


def quotes(filename, output_filename):
    file = Path(filename)
    with open(file, encoding="utf-8") as f:
        content = f.read().split("---")
    quotes = []
    for quote in content:
        quote = quote.strip().splitlines()
        text = []
        author = ""
        for line in quote:
            if line.startswith("-- "):
                author = line
            else:
                text.append(line)
        if len(author) > 0:
            text.append("")
            text.append(author)
        quote_new = '\n'.join(text)
        numbers = "0123456789"
        chars = ".,?!:;абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ—»"
        for number in numbers:
            for char in chars:
                quote_new = quote_new.replace(char + number, char + " " +number)
        quote_new = quote_new.replace(" Глава...","")
        quote_new = quote_new.replace("Глава...","")
        quotes.append(quote_new)
    with open(Path(output_filename), "w", encoding="utf8") as text_file:
        text_file.write("\n\n---\n\n".join(quotes))


quotes("data/1.md", "data/2.md")
