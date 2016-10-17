# -*- coding: utf-8 -*-
"""Launcher module."""

import time

import conf
from app import BaseApplication

if conf.IS_WIPY:
    import untplib
    from machine import RTC


class WordClock(BaseApplication):
    """Class for displaying wordclock time."""

    def __init__(self, *args, **kwargs):
        """Initialize the wordclock."""
        super(WordClock, self).__init__(*args, **kwargs)
        # Create synchronization tools
        self._rtc = RTC()
        self._ntp = untplib.NTPClient()
        # Set last time synced to never
        self._last_sync = 0
        # Set the default color
        self.color = conf.CLOCK_COLOR
        # TODO: Load language
        import lang.en as en
        self._lang = en.WordClockLang()
        self._grid.overlay = self._lang.word_grid

    def sync_wipy_time(self):
        """Sync the time with NTP."""
        resp = self._ntp.request(conf.NTP_SERVER)
        self._rtc.init(time.localtime(time.time()
                                      + resp.offset
                                      + conf.TIME_SHIFT))
        self._last_sync = time.time()

    def run(self):
        """Run the wordclock application."""
        while True:
            if conf.IS_WIPY and time.time() - self._last_sync > conf.NTP_DELAY:
                self.sync_wipy_time()
            self.show_time()
            yield

    def show_time(self):
        """Show current time in words."""
        # Reset the grid
        self._grid.reset()

        if conf.IS_WIPY:
            _, _, _, h, m, s, _, _ = time.localtime()
        else:
            localtime = time.localtime()
            h = localtime.tm_hour
            m = localtime.tm_min
            s = localtime.tm_sec

        # Display the time
        for x, y in self._lang.time_to_leds(h, m, s):
            self._grid.draw_point(x, y, self.color)

        # Show the grid
        self._grid.show()


def demo():
    """Demo of the wordclock."""
    wordclock = WordClock().run()
    while True:
        wordclock.send(None)


if __name__ == '__main__':
    demo()
