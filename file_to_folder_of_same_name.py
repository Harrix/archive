from pathlib import Path
import shutil

path = input()

extension = ".stl"

for file in Path(path).glob("**/*"):
    if file.is_file() and file.suffix.lower() == extension:
        path_new = path / Path(file.stem)
        path_new.mkdir(parents=True, exist_ok=True)
        Path.rename(file, path_new / Path(file.name))
