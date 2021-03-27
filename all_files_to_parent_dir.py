from pathlib import Path
import shutil

path = input()

for child_dir in Path(path).iterdir():
    for file in Path(child_dir).glob("**/*"):
        if file.is_file():
            file.replace(child_dir / file.name)
    for file in Path(child_dir).glob("**/*"):
        if file.is_dir():
            shutil.rmtree(file)
    print("Fix {}".format(child_dir))
