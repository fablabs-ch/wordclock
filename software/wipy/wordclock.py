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
        # Sync the time on the Wipy
        if conf.IS_WIPY:
            self.sync_wipy_time()
        import lang.en as en
        self._lang = en.WordClockLang()
        self._grid.overlay = self._lang.word_grid

    @staticmethod
    def sync_wipy_time():
        """Sync the time with NTP."""

        client = untplib.NTPClient()
        resp = client.request('0.ch.pool.ntp.org')
        rtc = RTC()
        rtc.init(time.localtime(time.time() + resp.offset + conf.TIME_SHIFT))

    def run(self):
        """Run the wordclock application."""
        while True:
            self.show_time()
            yield
            if conf.IS_WIPY:
                time.sleep_ms(900)
            else:
                time.sleep(9/10)

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
            self._grid.draw_point(x, y, (255, 100, 255))

        # Show the grid
        self._grid.show()


def demo():
    """Demo of the wordclock."""
    wordclock = WordClock().run()
    while True:
        wordclock.send(None)


if __name__ == '__main__':
    demo()
