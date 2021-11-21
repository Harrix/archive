from pathlib import Path
import shutil


def all_files_to_parent_dir(path: str) -> None:
    for child_dir in Path(path).iterdir():
        for file in Path(child_dir).glob("**/*"):
            if file.is_file():
                file.replace(child_dir / file.name)
        for file in Path(child_dir).glob("**/*"):
            if file.is_dir():
                shutil.rmtree(file)
        print("Fix {}".format(child_dir))


if __name__ == "__main__":
    path = input()
    if path:
        all_files_to_parent_dir(path)
    else:
        all_files_to_parent_dir("D:\\Downloads\\_3d")
