# -*- coding: utf-8 -*-
"""Controller of the neopixels."""

import conf


if conf.IS_WIPY:
    from ws2812 import WS2812

if conf.HAS_XTERMCOLOR:
    # Force xtermcolor to use xterm ANSI color codes
    from os import environ
    environ['TERM'] = "xterm"
    # Import xtermcolor
    from xtermcolor import colorize
    from xtermcolor.ColorMap import XTermColorMap


# pylint: disable=too-few-public-methods
class Controller():
    """Controller for the neopixels."""

    def __init__(self, width, height):
        """Initialize the controller."""
        self._width = width
        self._height = height
        self._grid = [(0, 0, 0)] * (width * height)
        # On the wipy, load the neopixel controller
        if conf.IS_WIPY:
            self._controller = WS2812(self._width * self._height)

    def _at(self, x, y):
        """Translate a <x,y> position to the corresponding index in the grid.

        Args:
          x (int): the x position in the grid.
          y (int): the y position in the grid.

        Returns:
          The index in the grid array corresponding to neopixel <x,y>.

        """
        # Inverse the column number in odd rows (because they are addressed
        # right to left.
        if x % 2:
            y = self._height - y - 1
        # Translate the <x,y> position to the grid array index.
        return y + (x * self._height)

    def _show(self, grid, overlay=None):
        """Show the grid.

        Display it on the neopixels if WS2812 is available, and display it on
        the terminal if xtermcolor is available.

        """
        # Save as the new current grid
        self._grid = list(grid)

        # Use the controller to show the LEDs on the wipy
        if conf.IS_WIPY:
            # Show the grid on the neopixels.
            self._controller.show(self._grid)

        # If the platform support xtermcolor
        ansi = None
        if conf.HAS_XTERMCOLOR:
            # Transform rgb color tuples to rgb integer
            rgbs = (int("0x{0[0]:02X}{0[1]:02X}{0[2]:02X}".format(pixel), 0)
                    for pixel in self._grid)
            # Transform rgb integers to ansi color codes
            ansi = [XTermColorMap().convert(rgb)[0] for rgb in rgbs]
            # Show the grid in the terminal

        # If on debug mode, print the grid
        if conf.DEBUG:
            for x in range(self._height):
                for y in range(self._width):
                    if conf.HAS_XTERMCOLOR:
                        symbol = overlay[x][y] if overlay else " "
                        cell = colorize(" " + symbol,
                                        rgb=0,
                                        ansi_bg=ansi[self._at(x, y)])
                    else:
                        symbol = " "
                        if self._grid[self._at(x, y)] != (0, 0, 0):
                            symbol = overlay[x][y] if overlay else "X"
                        cell = " " + symbol
                    print(cell, end='')
                print()
            print()

    def show(self, grid, transition=None, overlay=None):
        """Show a grid."""
        # TODO: Support transition
        if transition is None:
            self._show(grid, overlay)


CONTROLLER = Controller(12, 12)
