# -*- coding: utf-8 -*-
"""Main application module."""

from app import BaseApplication
from meteo import Meteo


# pylint: disable=too-few-public-methods
class Main(BaseApplication):
    """Main application."""

    def __init__(self, *args, **kwargs):
        """Initialize the wordclock."""
        super(Main, self).__init__(*args, **kwargs)
        self._app = Meteo()

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
    app = Main()
    app.run()


if __name__ == '__main__':
    main()
