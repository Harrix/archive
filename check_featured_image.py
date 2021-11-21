from pathlib import Path

path = input()

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
