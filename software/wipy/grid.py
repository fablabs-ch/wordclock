# -*- coding: utf-8 -*-
"""Module to control a NeoPixels grid."""

from ws2812 import WS2812


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

    def set_square(self, x, y, w, h, rgb):
        """Set pixels in the square at (x,y) of size (w,h) to <rgb>."""
        for rx in range(h):
            for ry in range(w):
                self.set_pixel(x + rx, y + ry, rgb)


g = Grid(12,12)
g.set_square(0,0,12,12,(255, 0, 0))
g.set_square(1,4,4,10,(255, 255, 255))
g.set_square(4,1,10,4,(255, 255, 255))
g.display()
