# -*- coding: utf-8 -*-
# pylint: disable=too-many-arguments,invalid-name
"""Control a grid of neopixels.

This module assumes a grid of neopixels connected as following:

×->  0 ->  1 ->  2 ->  3 ->  4 ->  5 -v
                                      |
 v- 11 <- 10 <-  9 <-  8 <-  7 <-  6 -<
 |
 >- 12 -> 13 -> 14 -> 15 -> 16 -> 17 -v
                                      |
                             … <- 18 -<

With the neopixels 0 being at position <0,0> and being placed at the top left
of the grid.

Authors: Fabien Dubosson <fabien.dubosson@gmail.com>

"""

from chars import chars

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


class Grid():
    """A grid of neopixels."""

    def __init__(self, width=12, height=12, one_indexed=False, overlay=None):
        """Create a grid of <width>×<height> neopixels.

        Args:
            width (int): the width of the grid.
            height (int): the height of the grid.
            one_indexed (bool): if indexing is done starting at one.
            overlay (list of list of str): The grid overlay, used to print on
              terminal.
        """
        # Save parameters for later use
        self._width = width
        self._height = height
        self._one_indexed = one_indexed
        self._overlay = overlay
        # Create the grid of neopixels.
        self._grid = [(0, 0, 0)] * (width * height)
        # The controller of the neopixels
        # Its creation is delayed because it turns off the neopixels.
        self._controller = None

    def _at(self, x, y, corrected=True):
        """Translate a <x,y> position to the corresponding index in the grid.

        Args:
          x (int): the x position in the grid.
          y (int): the y position in the grid.

        Returns:
          The index in the grid array corresponding to neopixel <x,y>.

        """
        # Handle one-indexed addressing.
        if self._one_indexed and corrected:
            x -= 1
            y -= 1
        # Inverse the column number in odd rows (because they are addressed
        # right to left.
        if x % 2:
            y = self._height - y - 1
        # Translate the <x,y> position to the grid array index.
        return y + (x * self._height)

    def reset(self):
        """Reset the grid by setting off all neopixels."""
        for i in range(len(self._grid)):
            self._grid[i] = (0, 0, 0)

    def show(self):
        """Show the grid.

        Display it on the neopixels if WS2812 is available, and display it on
        the terminal if xtermcolor is available.

        """
        if HAS_WS2812:
            # Create the controller if not already existing.
            if self._controller is None:
                self._controller = WS2812(self._width * self._height)
            # Show the grid on the neopixels.
            self._controller.show(self._grid)

        if HAS_ANSI:
            # Transform rgb color tuples to rgb integer
            rgbs = (int("0x{0[0]:02X}{0[1]:02X}{0[2]:02X}".format(pixel), 0)
                    for pixel in self._grid)
            # Transform rgb integers to ansi color codes
            ansi = [XTermColorMap().convert(rgb)[0] for rgb in rgbs]
            # Show the grid in the terminal
            for x in range(self._height):
                for y in range(self._width):
                    overlay = " "
                    if self._grid[self._at(x, y, False)] != (0, 0, 0) and \
                       self._overlay:
                        overlay = self._overlay[x][y]
                    print(colorize(" " + overlay,
                                   rgb=0,
                                   ansi_bg=ansi[self._at(x, y, False)]),
                          end='')
                print()
            print()

    def draw_point(self, x, y, fill):
        """Draw the pixel at position <x,y>.

        Args:
          x (int): the x position of the neopixel.
          y (int): the y position of the neopixel.
          fill ((int,int,int)): the color of the neopixel.

        """
        if x < 0 or y < 0 or x >= self._height or y >= self._width:
            return
        self._grid[self._at(x, y)] = fill

    def draw_points(self, xs, ys, fills):
        """Draw pixels at position <xs, ys>.

        The <fills> argument can be a list for drawing different colors to each
        pixel.

        Args:
          xs (list of int): the x positions of the neopixels.
          ys (list of int): the y positions of the neopixels.
          fills ((int,int,int)): the color of the neopixels.

        """
        assert len(xs) == len(ys)
        for p, _ in enumerate(xs):
            fill = fills[p] if isinstance(fills, list) else fills
            self._grid[self._at(xs[p], ys[p])] = fill

    def draw_subgrid(self, x0, y0, subgrid, mask=None):
        """Draw subgrid starting at <x0,y0>.

        Args:
          x0 (int): the x position of the subgrid.
          y0 (int): the y position of the subgrid.
          subgrid (list of list of (int,int,int)): the subgrid containing the
            colors of the neopixels.

        """
        for x, _ in enumerate(subgrid):
            for y, _ in enumerate(subgrid[x]):
                if subgrid[x][y] and (not mask or mask[x][y]):
                    self.draw_point(x0 + x, y0 + y, subgrid[x][y])

    def draw_line(self, x0, y0, x1, y1, fill=None):
        """Draw a line from position <x0,y0> to <x1,y1>.

        Algorithm from:
        https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#Python

        Args:
          x0 (int): the x position of the first point.
          y0 (int): the y position of the first point.
          x1 (int): the x position of the second point.
          y1 (int): the y position of the second point.
          fill ((int,int,int)): the color of the rectangle.

        """
        # The following algorithm doesn't work for horizontal lines. Use
        # draw_rectangle for this special case.
        # x0, y0, x1, y1 = bounding_box(x0, y0, x1, y1)
        # if x0 == x1:
        #     self.draw_rectangle(x0, y0, y1 - y0, 1, border=fill)
        #     return
        # Line algorithm
        dx = abs(x1 - x0)
        dy = abs(y1 - y0)
        x, y = x0, y0
        sx = -1 if x0 > x1 else 1
        sy = -1 if y0 > y1 else 1
        if dx > dy:
            err = dx // 2
            while x != x1:
                self.draw_point(x, y, fill)
                err -= dy
                if err < 0:
                    y += sy
                    err += dx
                x += sx
        else:
            err = dy // 2
            while y != y1:
                self.draw_point(x, y, fill)
                err -= dx
                if err < 0:
                    x += sx
                    err += dy
                y += sy
        self.draw_point(x, y, fill)

    def draw_rectangle(self, x0, y0, x1, y1, fill=None, border=None):
        """Draw a square at position <x0,y0> of size <w,h> with specified colors.

        Args:
          x0 (int): the x position of the top left pixel of the rectangle.
          y0 (int): the y position of the top left pixel of the rectangle.
          x1 (int): the x position of the bottom right pixel of the rectangle.
          y1 (int): the y position of the bottom right pixel of the rectangle.
          fill ((int,int,int)): the color of the rectangle.
          border ((int,int,int)): the color of the border of the rectangle.

        """
        # Correct points order
        x0, y0, x1, y1 = min(x0, x1), min(y0, y1), max(x0, x1), max(y0, y1)
        # Fill the rectangle
        if fill:
            for x in range(x1 - x0 + 1):
                for y in range(y1 - y0 + 1):
                    self.draw_point(x0 + x, y0 + y, fill)
        # Draw the border
        if border:
            for x in range(x1 - x0):
                self.draw_point(x0 + x, y0, border)
                self.draw_point(x0 + x, y1, border)
            for y in range(y1 - y0):
                self.draw_point(x0, y0 + y, border)
                self.draw_point(x1, y0 + y, border)

    def draw_circle(self, x0, y0, radius, fill=None, border=None):
        """Draw a circle at position <x,y> of radius <r>.

        Algorithms from:
        https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
        http://stackoverflow.com/a/1201304/2311626

        Args:
          x0 (int): the x position of the center of the circle.
          y0 (int): the y position of the center of the circle.
          radius (int): the radius of the circle.
          fill ((int,int,int)): the color of the circle.
          border ((int,int,int)): the color of the border of the circle.

        """
        x = radius
        y = 0
        err = 0
        while x >= y:
            if fill:
                self.draw_line(x0 - x, y0 + y, x0 + x, y0 + y, fill)
                self.draw_line(x0 - y, y0 + x, x0 + y, y0 + x, fill)
                self.draw_line(x0 + y, y0 - x, x0 - y, y0 - x, fill)
                self.draw_line(x0 + x, y0 - y, x0 - x, y0 - y, fill)
            if border:
                self.draw_point(x0 + x, y0 + y, border)
                self.draw_point(x0 + y, y0 + x, border)
                self.draw_point(x0 - y, y0 + x, border)
                self.draw_point(x0 - x, y0 + y, border)
                self.draw_point(x0 - x, y0 - y, border)
                self.draw_point(x0 - y, y0 - x, border)
                self.draw_point(x0 + y, y0 - x, border)
                self.draw_point(x0 + x, y0 - y, border)
            y += 1
            err += 1 + 2 * y
            if 2 * (err - x) + 1 > 0:
                x -= 1
                err += 1 - 2 * x

    def draw_char(self, x0, y0, char, fill):
        """Draw a 3x5 char at position <x0,y0>.

        Args:
          x0 (int): the x position of the center of the circle.
          y0 (int): the y position of the center of the circle.
          char (int): the char to draw.
          fill ((int,int,int)): the color of the circle.

        """
        char = char[0].upper()
        grid = [[fill] * 3] * 5
        self.draw_subgrid(x0, y0, grid, mask=chars[char])


def demo():
    """Demo of the module."""
    # Swiss flag
    g = Grid(12, 12)
    g.draw_rectangle(0, 0, 11, 11, fill=(255, 0, 0))
    g.draw_rectangle(1, 4, 10, 7, fill=(255, 255, 255))
    g.draw_rectangle(4, 1, 7, 10, fill=(255, 255, 255))
    g.show()

    # Sight
    g = Grid(11, 11)
    g.draw_rectangle(0, 0, 10, 10, fill=(100, 100, 100))
    # Fill circle
    g.draw_circle(5, 5, 4, fill=(255, 200, 200))
    # Orthogonals
    g.draw_line(1, 5, 9, 5, fill=(255, 100, 100))
    g.draw_line(5, 1, 5, 9, fill=(255, 100, 100))
    # Diagonals
    g.draw_line(1, 1, 9, 9, fill=(255, 200, 100))
    g.draw_line(1, 9, 9, 1, fill=(255, 200, 100))
    # Circle border
    g.draw_circle(5, 5, 4, border=(255, 0, 0))
    g.draw_point(5, 5, (255, 255, 255))
    g.show()

    # WordClock
    overlay = [["V", "I", "T", "K", "I", "S", "W", "H", "A", "L", "F", "I"],
               ["T", "E", "N", "A", "L", "Q", "U", "A", "R", "T", "E", "R"],
               ["S", "T", "W", "E", "N", "T", "Y", "-", "F", "I", "V", "E"],
               ["P", "A", "S", "T", "Y", "T", "O", "B", "O", "N", "E", "Ç"],
               ["T", "W", "O", "T", "H", "R", "E", "E", "F", "O", "U", "R"],
               ["F", "I", "V", "E", "S", "I", "X", "S", "E", "V", "E", "N"],
               ["E", "I", "G", "H", "T", "N", "I", "N", "E", "T", "E", "N"],
               ["E", "L", "E", "V", "E", "N", "T", "W", "E", "L", "V", "E"],
               ["L", "F", "K", "O", "C", "L", "O", "C", "K", "N", "J", "X"],
               ["T", "W", "I", "T", "Q", "H", "U", "X", "P", "M", "K", "Y"],
               ["N", "B", "P", "K", "*", "*", "*", "*", "K", "Y", "L", "R"],
               ["U", "A", "O", "J", "T", "R", "É", "Y", "P", "E", "B", "J"]]
    g = Grid(12, 12, overlay=overlay)
    g.draw_rectangle(0, 0, 11, 11, fill=(100, 100, 100))
    g.draw_points([0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 6, 6, 6, 6, 10],
                  [1, 2, 4, 5, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 5, 6, 7, 8, 4],
                  (0, 255, 255))
    g.show()

    # Time digits
    g = Grid(12, 12)
    g.draw_rectangle(0, 0, 11, 11, fill=(100, 100, 100))
    g.draw_points([1, 3], [9, 9], (255, 100, 100))
    g.draw_char(0, 1, '2', (100, 100, 255))
    g.draw_char(0, 5, '3', (100, 100, 255))
    g.draw_char(7, 4, '5', (100, 100, 255))
    g.draw_char(7, 8, '7', (100, 100, 255))
    g.show()

    # Letters
    g = Grid(12, 12)
    for l in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        g.draw_rectangle(0, 0, 11, 11, fill=(100, 100, 100))
        g.draw_char(3, 4, l, (100, 100, 255))
        g.show()


if __name__ == '__main__':
    demo()
