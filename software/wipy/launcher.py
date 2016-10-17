# -*- coding: utf-8 -*-
"""Launcher application module."""

import socket

import conf
from wordclock import WordClock

if conf.IS_WIPY:
    from network import WLAN

class Launcher():
    """Launcher application."""

    def __init__(self, *args, **kwargs):
        """Initialize the wordclock."""
        super(Launcher, self).__init__(*args, **kwargs)
        self._app = WordClock()

    def run(self):
        """Run the wordclock."""
        server = self.server()
        clock = WordClock().run()
        coroutine = clock
        while True:
            try:
                coroutine.send(None)
                val = server.send(None)
            except StopIteration:
                break

    @staticmethod
    def server():
        """Run the server for remote control."""
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        ipaddr = WLAN().ifconfig()[0]
        s.bind((ipaddr, 9999))
        s.setblocking(False)
        s.listen()
        while True:
            yield
            try:
                client, _ = s.accept()
                while True:
                    cmd = client.read()
                    if cmd == b'':
                        break
                    if cmd is not None:
                        cmd = cmd.decode('ascii').split()[0].strip()
                    yield cmd
            except OSError:
                continue


def main():
    """Entry point of the application"""
    app = Launcher()
    app.run()


if __name__ == '__main__':
    main()
