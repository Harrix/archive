# harrix-log

Colored logging class based on the standard python logging class.

![GitHub](https://img.shields.io/github/license/Harrix/harrix-log) ![PyPI](https://img.shields.io/pypi/v/harrix-log)

## Quick start

```py
import harrixlog as hl

hl.log.debug("Debug message")
hl.log.error("Error message")
hl.log.info("x = {}".format(hl.log.text_red_background(6)))
```

![Colored text in the console](https://raw.githubusercontent.com/Harrix/harrix-log/main/img/log_example.png)

## Install

Pip: `pip install harrix-log`.

Pipenv: `pipenv install harrix-log`.

## Update

Pip: `pip update harrix-log`.

Pipenv: `pipenv update harrix-log`.

## Development

See [development.md](https://github.com/Harrix/harrix-log/blob/main/development.md).
