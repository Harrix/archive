from pathlib import Path


def check_featured_image(path:str) -> None:
    """This function check `featured_image` in every child directory.
    Not recursively.

    Args:
      path: path to the directory being checked.

    Returns:
      True - if each child folder contains a file `featured_image`.
      False - else.
    """
    is_correct = True

    for child_dir in Path(path).iterdir():
        is_featured_image = False
        for file in Path(child_dir).glob("**/*"):
            if file.is_file() and "featured-image" in file.name:
                is_featured_image = True
        if not is_featured_image:
            is_correct = False
            print("{} without featured-image".format(child_dir))

    if is_correct:
        print("All correct")
    return is_correct


if __name__ == "__main__":
    path = input()
    if path:
        check_featured_image(path)
    else:
        lst = ["D:\\Dropbox\\IT\\3D printer\\Models\\Print",
        "D:\\Dropbox\\IT\\3D printer\\Models\\Printed",
        "D:\\Dropbox\\IT\\3D printer\\Models\\Unprinted",
        "D:\\Dropbox\\IT\\3D printer\\Models - Box\\Printed",
        "D:\\Dropbox\\IT\\3D printer\\Models - Box\\Unprinted",
        "D:\\Dropbox\\IT\\3D printer\\Models - Cable\\Printed",
        "D:\\Dropbox\\IT\\3D printer\\Models - Cable\\Unprinted",
        "D:\\Dropbox\\IT\\3D printer\\Models - Miscellaneous\\Print",
        "D:\\Dropbox\\IT\\3D printer\\Models - Miscellaneous\\Printed",
        "D:\\Dropbox\\IT\\3D printer\\Models - Miscellaneous\\Unprinted",
        "D:\\Dropbox\\IT\\3D printer\\Models - Puzzle\\Bad",
        "D:\\Dropbox\\IT\\3D printer\\Models - Puzzle\\Printed",
        "D:\\Dropbox\\IT\\3D printer\\Models - Puzzle\\Unprinted",
        "D:\\Dropbox\\IT\\3D printer\\Models - Science\\Printed",
        "D:\\Dropbox\\IT\\3D printer\\Models - Science\\Unprinted"]
        for path in lst:
            check_featured_image(path)
