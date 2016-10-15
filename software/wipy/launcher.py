# -*- coding: utf-8 -*-
"""Launcher application module."""

import socket
import time

from app import BaseApplication
from network import WLAN
from wordclock import WordClock
from meteo import Meteo


# pylint: disable=too-few-public-methods
class Launcher(BaseApplication):
    """Launcher application."""

    def __init__(self, *args, **kwargs):
        """Initialize the wordclock."""
        super(Launcher, self).__init__(*args, **kwargs)
        self._app = WordClock('en')

    def run(self):
        """Run the wordclock."""
        server = self.server()
        coroutine = self._app.run()
        while True:
            try:
                coroutine.send(None)
                val = server.send(None)
                if val is not None:
                    coroutine.close()
                    coroutine = Meteo().run()
            except StopIteration:
                break

    def server(self):
        """Run the server for remote control."""
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        ip = WLAN().ifconfig()[0]
        s.bind((ip, 9999))
        s.setblocking(False)
        s.listen(5)
        while True:
            yield
            try:
                client, _ = s.accept()
            except OSError:
                continue
            time.sleep_ms(1000)
            cmd = client.readline()
            client.close()
            yield cmd


def main():
    """Entry point of the application"""
    app = Launcher()
    app.run()


if __name__ == '__main__':
    main()
