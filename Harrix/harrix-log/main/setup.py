from setuptools import find_packages, setup
import pathlib

here = pathlib.Path(__file__).parent.resolve()
long_description = (here / "README.md").read_text(encoding="utf-8")

setup(
    name="harrix-log",
    version="1.0",
    description="Colored logging class based on the standard python logging class",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/Harrix/harrix-log",
    author="Anton Sergienko",
    author_email="anton.b.sergienko@gmail.com",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    zip_safe=False
)
