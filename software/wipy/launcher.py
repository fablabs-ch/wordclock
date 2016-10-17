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
        # WordClock application
        self._app = WordClock()
        self._run = self._app.run()
        # Server application
        self._server = self.server()

    def run(self):
        """Run the wordclock."""
        while True:
            try:
                self._run.send(None)
                self.interpret_command(self._server.send(None))
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
                        cmd = cmd.decode('ascii').split('\r\n')[0].strip()
                    yield cmd
            except OSError:
                continue

    def interpret_command(self, cmd_string):
        """Interpret a command."""
        if cmd_string is None:
            return

        words = cmd_string.split(' ')
        cmd = words[0]
        print(cmd, words)

        if cmd == 'set_color':
            self._app.color = (int(words[1]), int(words[2]), int(words[3]))


def main():
    """Entry point of the application"""
    app = Launcher()
    app.run()


if __name__ == '__main__':
    main()
