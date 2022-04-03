# Development

If you don't have [pipenv](https://pipenv.pypa.io/en/latest/) installed, then you can install it via the commands:

```console
python -m pip install virtualenv
python -m pip install pipenv
```

Installing packages by file `Pipfile`:

```console
pipenv install --dev
pipenv shell
```

Run pdoc:

```console
pdoc --docformat="google" src\harrixlog\
```

Run the file `generate_docs.py` to generate the documentation.

Example of installing a package under development in a test project:

```console
pipenv install -e C:/GitHub/harrix-log
```
