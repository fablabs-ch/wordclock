# -*- coding: utf-8 -*-
"""Control a grid of neopixels.

Authors: Fabien Dubosson <fabien.dubosson@gmail.com>

"""

# Try to import the ws2812 module.
# If it is not supported, disable it in the code.
try:
    from ws2812 import WS2812
    HAS_WS2812 = True
except ImportError:
    HAS_WS2812 = False

# Try to import the xtermcolor module.
# If it is not supported, disable it in the code.
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

    def __init__(self, width=12, height=12):
        """Create a grid of <width>×<height> neopixels.

        Args:
            width (int): the width of the grid.
            height (int): the height of the grid.
        """
        # Save width, height and controller for later use
        self._width = width
        self._height = height
        # Set neopixels off by default
        self._grid = [(0, 0, 0)] * (width * height)
        # The controller of the neopixels
        # Its creation is delayed because it turns off the neopixels.
        self._controller = None

    def _at(self, x, y):
        """Translate a <x,y> position to the corresponding index in the grid.

        This function assumes a grid of neopixels connected as following:

        ×->  0 ->  1 ->  2 ->  3 ->  4 ->  5 -v
                                              |
         v- 11 <- 10 <-  9 <-  8 <-  7 <-  6 -<
         |
         >- 12 -> 13 -> 14 -> 15 -> 16 -> 17 -v
                                              |
                                     … <- 18 -<

        With the neopixels 0 being at position <0,0> and on top left of the
        grid.

        Args:
          x (int): the x position in the grid.
          y (int): the y position in the grid.

        Returns:
          The index of the grid array corresponding to point <x,y> in the grid.

        """
        # Reverse the neopixels' number (from right to left instead of left to
        # right if accessing an odd rows.
        if x % 2:
            y = self._height - y - 1
        # Translate the <x,y> position to the grid array index.
        return y + (x * self._height)

    def reset(self):
        """Reset the grid by setting off all neopixels."""
        for i in range(len(self._grid)):
            self._grid[i] = (0, 0, 0)

    def show(self):
        """Show the grid to the neopixels."""
        if HAS_WS2812:
            # Create the controller if not already existing.
            if self._controller is None:
                self._controller = WS2812(self._width * self._height)
            # Show the grid on the neopixels.
            self._controller.show(self._grid)

        if HAS_ANSI:
            # Transform grid tuples to integer
            rgbs = (int("0x{0[0]:02X}{0[1]:02X}{0[2]:02X}".format(pixel), 0)
                    for pixel in self._grid)
            # Transform rgb integers to ansi color codes
            ansi = [XTermColorMap().convert(p)[0]
                    for p in rgbs]
            # Print the grid in the terminal
            for x in range(self._height):
                for y in range(self._width):
                    print(colorize("  ",
                                   ansi=10,
                                   ansi_bg=ansi[self._at(x, y)]),
                          end='')
                print()

    def set_pixel(self, x, y, rgb):
        """Set the pixel at position <x,y> to the color <rgb>.

        Args:
          x (int): the x position of the neopixel to change.
          y (int): the y position of the neopixel to change.
          rgb ((int,int,int)): the new color of the neopixel.

        """
        self._grid[self._at(x, y)] = rgb

    # pylint: disable=invalid-name
    def set_pixels(self, x, y, rgbs):
        """Set pixels starting at <x,y> to the colors of the subgrids <rgbs>.

        Args:
          x (int): the x position of the first pixel to change.
          y (int): the y position of the first pixel to change.
          rgbs (list of list of (int,int,int)): the subgrid containing the new
            colors of the neopixels.

        """
        for ry, _ in enumerate(rgbs):
            for rx, _ in enumerate(rgbs[ry]):
                self.set_pixel(x + rx, y + ry, rgbs[ry][rx])

    # pylint: disable=too-many-arguments,invalid-name
    def draw_square(self, x, y, w, h, rgb):
        """Draw a square at position <x,y> of size <w,h> to the color <rgb>.

        Args:
          x (int): the x position of the top left pixel of the rectangle.
          y (int): the y position of the top left pixel of the rectangle.
          w (int): the width of the rectangle.
          h (int): the height of the rectangle.
          rgb ((int,int,int)): the color of the rectangle.

        """
        for rx in range(h):
            for ry in range(w):
                self.set_pixel(x + rx, y + ry, rgb)


def demo():
    """Demo of the module."""
    # Show a swiss flag on a 12x12 grid.
    g = Grid(12, 12)
    g.draw_square(0, 0, 12, 12, (255, 0, 0))
    g.draw_square(1, 4, 4, 10, (255, 255, 255))
    g.draw_square(4, 1, 10, 4, (255, 255, 255))
    g.show()

if __name__ == '__main__':
    demo()
