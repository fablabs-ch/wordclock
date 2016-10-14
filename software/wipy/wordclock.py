# -*- coding: utf-8 -*-
"""WordClock application module."""

import time
from app import BaseApplication
from meteo import Meteo


class WordClock(BaseApplication):
    """WordClock main application."""

    def __init__(self, timer, *args, **kwargs):
        """Initialize the wordclock."""
        super(WordClock, self).__init__(*args, **kwargs)
        self._app = Meteo()
        self._timer = timer

    def run(self):
        """Coroutine to run the wordclock."""
        co = self._app.run()
        next(co)
        while True:
            try:
                co.send(None)
                time.sleep(1)
                # time.sleep_ms(self._timer)
            except StopIteration:
                break


def main():
    """Entry point of the application"""
    wordclock = WordClock(1000)
    loop = wordclock.run()
    next(loop)
    while True:
        try:
            loop.send(None)
        except StopIteration:
            break


if __name__ == '__main__':
    main()
