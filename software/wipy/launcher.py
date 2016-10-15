# -*- coding: utf-8 -*-
"""Launcher application module."""

from app import BaseApplication
from wordclock import WordClock


# pylint: disable=too-few-public-methods
class Launcher(BaseApplication):
    """Launcher application."""

    def __init__(self, *args, **kwargs):
        """Initialize the wordclock."""
        super(Launcher, self).__init__(*args, **kwargs)
        self._app = WordClock('en')

    def run(self):
        """Run the wordclock."""
        coroutine = self._app.run()
        while True:
            try:
                coroutine.send(None)
                # time.sleep_ms(self._timer)
            except StopIteration:
                break


def main():
    """Entry point of the application"""
    app = Launcher()
    app.run()


if __name__ == '__main__':
    main()
