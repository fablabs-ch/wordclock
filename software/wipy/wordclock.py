# -*- coding: utf-8 -*-
"""Main application module."""

import time
from app import BaseApplication


class WordClock(BaseApplication):
    """Class for displaying wordclock time."""

    def __init__(self, language, *args, **kwargs):
        """Initialize the wordclock."""
        super(WordClock, self).__init__(*args, **kwargs)
        self._language = language
        import lang.en as en
        self._lang = en.WordClockLang()
        self._grid.overlay = self._lang.word_grid

    def run(self):
        """Run the wordclock application."""
        while True:
            self.show_time()
            time.sleep(0.9)

    def show_time(self):
        """Show current time in words."""
        # Reset the grid
        self._grid.reset()

        # Get the current time
        localtime = time.localtime()
        h = localtime.tm_hour
        m = localtime.tm_min
        s = localtime.tm_sec

        # Display the time
        for x, y in self._lang.time_to_leds(h, m, s):
            self._grid.draw_point(x, y, (255, 100, 255))

        # Show the grid
        self._grid.show()


def demo():
    """Demo of the wordclock."""
    wordclock = WordClock('en')
    wordclock.run()


if __name__ == '__main__':
    demo()
