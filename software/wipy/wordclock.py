# -*- coding: utf-8 -*-
"""Main application module."""

import time

import untplib
from app import BaseApplication


class WordClock(BaseApplication):
    """Class for displaying wordclock time."""

    # TODO: conf.lang
    def __init__(self, language, *args, **kwargs):
        """Initialize the wordclock."""
        super(WordClock, self).__init__(*args, **kwargs)
        # TODO: IS WIPY
        self.sync_time()
        self._language = language
        import lang.en as en
        self._lang = en.WordClockLang()
        self._grid.overlay = self._lang.word_grid

    def sync_time(self):
        """Sync the time with NTP."""
        client = untplib.NTPClient()
        resp = client.request('0.ch.pool.ntp.org')
        print("Offset is ", resp.offset)

        from machine import RTC
        import time

        rtc = RTC()
        print("Adjusting clock by ", resp.offset, "seconds")
        rtc.init(time.localtime(time.time() + resp.offset))


    def run(self):
        """Run the wordclock application."""
        while True:
            self.show_time()
            yield
            time.sleep_ms(900)

    def show_time(self):
        """Show current time in words."""
        # Reset the grid
        self._grid.reset()

        # TODO: IS WIPY
        # Get the current time
        _, _, _, h, m, s, _, _ = time.localtime()

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
