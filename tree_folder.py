from pathlib import Path

space = "   "
branch = "│  "
tee = "├─ "
last = "└─ "


def tree(dir_path: Path, prefix: str = ""):
    contents = list(dir_path.iterdir())
    pointers = [tee] * (len(contents) - 1) + [last]
    for pointer, path in zip(pointers, contents):
        yield prefix + pointer + path.name
        if path.is_dir():
            extension = branch if pointer == tee else space
            yield from tree(path, prefix=prefix + extension)


path = input()
for line in tree(Path(path)):
    print(line)
