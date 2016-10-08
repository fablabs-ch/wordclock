# -*- coding: utf-8 -*-
# pylint: disable=invalid-name,too-many-arguments
"""Module to control a NeoPixels grid."""

try:
    from ws2812 import WS2812
except ImportError:
    pass

try:
    from xtermcolor import colorize
    from xtermcolor.ColorMap import XTermColorMap
except ImportError:
    pass


class Grid():
    """Class representing a grid of NeoPixels."""

    def __init__(self, width=12, height=12, invert=False, one_indexed=False):
        """Create a grid of <width>×<height> neopixels.

        width: Width of the grid.
        height: Height of the grid.
        invert: Boolean specifying if adressing should be inverted.
        """
        self._width = width
        self._height = height
        self._invert = invert
        self._one_indexed = one_indexed
        self._chain = None
        self._grid = [(0, 0, 0)] * (width * height)

    def at(self, x, y):
        """Translate a (x,y) position to grid index."""
        if self._one_indexed:
            x = x - 1
            y = y - 1
        if not self._invert:
            if x % 2:
                y = self._height - y - 1
            return y + (x * self._height)
        else:
            if y % 2:
                x = self._width - x - 1
            return x + (y * self._width)

    def display(self):
        """Display the grid to the real LEDs."""
        if self._chain is None:
            self._chain = WS2812(self._width * self._height)
        self._chain.show(self._grid)

    def reset(self):
        """Reset the grid to all LEDs off."""
        self._grid = [(0, 0, 0) for _ in self._grid]

    def set_pixel(self, x, y, rgb):
        """Set the pixel at position (x,y) to (r,g,b)"""
        self._grid[self.at(x, y)] = rgb

    def set_pixels(self, x, y, rgbs):
        """Set pixels starting at position (x,y) to the subgrid <rgbs>."""
        for ry, _ in enumerate(rgbs):
            for rx, _ in enumerate(rgbs[ry]):
                self.set_pixel(x + rx, y + ry, rgbs[ry][rx])

    def draw_square(self, x, y, w, h, rgb):
        """Set pixels in the square at (x,y) of size (w,h) to <rgb>."""
        for rx in range(h):
            for ry in range(w):
                self.set_pixel(x + rx, y + ry, rgb)

    def __str__(self):
        result = ""
        for x in range(self._height):
            for y in range(self._width):
                pixel = self._grid[self.at(x, y)]
                rgb = int("0x{0[0]:02X}{0[1]:02X}{0[2]:02X}".format(pixel), 0)
                bg = XTermColorMap().convert(rgb)[0]
                result += colorize("  ", ansi=10, ansi_bg=bg)
                # result += "[{0[0]:3} {0[1]:3} {0[2]:3}]\t".format(pixel)
            result += "\n"
        return result


# Swiss flag
g = Grid(12, 12)
g.draw_square(0, 0, 12, 12, (255, 0, 0))
g.draw_square(1, 4, 4, 10, (255, 255, 255))
g.draw_square(4, 1, 10, 4, (255, 255, 255))
print(g)

# Netherlands flag
g.draw_square(0, 0, 12, 4, (255, 0, 0))
g.draw_square(4, 0, 12, 4, (255, 255, 255))
g.draw_square(8, 0, 12, 4, (0, 0, 255))
print(g)
