from pathlib import Path


def file_to_folder_of_same_name(path: str, extension: str) -> None:
    for file in Path(path).glob("**/*"):
        if file.is_file() and (file.suffix.lower() in [extension, ""]):
            path_new = path / Path(file.stem)
            path_new.mkdir(parents=True, exist_ok=True)
            Path.rename(file, path_new / Path(file.name))


if __name__ == "__main__":
    path = input()
    if path:
        extension = input()
        file_to_folder_of_same_name(path, extension)
    else:
        file_to_folder_of_same_name("D:\\Downloads\\_3d", ".stl")
