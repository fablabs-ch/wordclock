# -*- coding: utf-8 -*-
"""Controller of the neopixels."""

# Try to import the ws2812 module.
# If it is not supported, disable related functionalities
try:
    from ws2812 import WS2812
    HAS_WS2812 = True
except ImportError:
    HAS_WS2812 = False

# Try to import the xtermcolor module.
# If it is not supported, disable related functionalities
try:
    # Force xtermcolor to use xterm ANSI color codes
    from os import environ
    environ['TERM'] = "xterm"
    # Import xtermcolor
    from xtermcolor import colorize
    from xtermcolor.ColorMap import XTermColorMap
    HAS_ANSI = True
except ImportError:
    HAS_ANSI = False


# pylint: disable=too-few-public-methods
class Controller():
    """Controller for the neopixels."""

    def __init__(self, width, height):
        """Initialize the controller."""
        self._width = width
        self._height = height
        self._grid = [(0, 0, 0)] * (width * height)
        if HAS_WS2812:
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
        # Save the Grid
        self._grid = list(grid)

        if HAS_WS2812:
            # Show the grid on the neopixels.
            self._controller.show(self._grid)
            # TODO: IS DEBUG
            for x in range(self._height):
                for y in range(self._width):
                    symbol = " "
                    if self._grid[self._at(x, y)] != (0, 0, 0) and \
                       overlay:
                        symbol = overlay[x][y]
                    print(symbol, end='')
                print()
            print()

        if HAS_ANSI:
            # Transform rgb color tuples to rgb integer
            rgbs = (int("0x{0[0]:02X}{0[1]:02X}{0[2]:02X}".format(pixel), 0)
                    for pixel in self._grid)
            # Transform rgb integers to ansi color codes
            ansi = [XTermColorMap().convert(rgb)[0] for rgb in rgbs]
            # Show the grid in the terminal
            for x in range(self._height):
                for y in range(self._width):
                    symbol = " "
                    if self._grid[self._at(x, y)] != (0, 0, 0) and \
                       overlay:
                        symbol = overlay[x][y]
                    print(colorize(" " + symbol,
                                   rgb=0,
                                   ansi_bg=ansi[self._at(x, y)]),
                          end='')
                print()
            print()

    def show(self, grid, transition=None, overlay=None):
        """Show a grid."""
        if transition is None:
            self._show(grid, overlay)
        # TODO: Support transition


CONTROLLER = Controller(12, 12)
