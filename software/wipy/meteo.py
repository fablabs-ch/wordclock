# -*- coding: utf-8 -*-
"""Meteo application."""

import app
import grid

# Colors abbreviation in 4 letters, for ICONS definitions alignment
YELL = (255, 200, 100)
GREY = (150, 150, 150)
BLUE = (50, 50, 255)
WHIT = (255, 255, 255)

# Meteo icons
ICONS = dict()

# Sunny
ICONS['sunny'] = [[None, None, None, None, YELL, None, None, None, None],
                  [None, YELL, None, None, YELL, None, None, YELL, None],
                  [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
                  [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
                  [YELL, YELL, YELL, YELL, YELL, YELL, YELL, YELL, YELL],
                  [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
                  [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
                  [None, YELL, None, None, YELL, None, None, YELL, None],
                  [None, None, None, None, YELL, None, None, None, None]]
# Mostly sunny
ICONS['mostly'] = [[None, None, None, None, YELL, None, None, None, None],
                   [None, YELL, None, None, YELL, None, None, None, None],
                   [None, None, YELL, YELL, YELL, YELL, GREY, None, None],
                   [None, None, YELL, YELL, YELL, GREY, GREY, GREY, None],
                   [YELL, YELL, YELL, GREY, YELL, GREY, GREY, GREY, None],
                   [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                   [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                   [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
                   [None, GREY, None, GREY, None, None, None, GREY, None]]


# Partially sunny
ICONS['partly'] = [[None, None, None, None, YELL, None, None, None, None],
                   [None, YELL, None, None, YELL, None, None, YELL, None],
                   [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
                   [None, None, YELL, YELL, YELL, YELL, YELL, GREY, None],
                   [YELL, YELL, YELL, YELL, YELL, YELL, GREY, GREY, None],
                   [None, None, YELL, YELL, YELL, GREY, GREY, GREY, GREY],
                   [None, None, YELL, YELL, YELL, GREY, GREY, GREY, GREY],
                   [None, YELL, None, None, GREY, None, GREY, GREY, GREY],
                   [None, None, None, None, None, None, None, GREY, None]]

# Cloudy
ICONS['cloud'] = [[None, None, None, None, None, None, None, None, None],
                  [None, None, None, None, None, None, GREY, None, None],
                  [None, None, None, None, None, GREY, GREY, GREY, None],
                  [None, None, None, GREY, None, GREY, GREY, GREY, None],
                  [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                  [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                  [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
                  [None, GREY, None, GREY, None, None, None, GREY, None],
                  [None, None, None, None, None, None, None, None, None]]

# Light rain
ICONS['light_r'] = [[None, None, None, None, None, None, GREY, None, None],
                    [None, None, None, None, None, GREY, GREY, GREY, None],
                    [None, None, None, GREY, None, GREY, GREY, GREY, None],
                    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
                    [None, GREY, None, GREY, None, None, None, GREY, None],
                    [BLUE, None, None, None, None, BLUE, None, None, None],
                    [None, None, None, BLUE, None, None, None, None, BLUE]]

# Heavy rain
ICONS['heavy_r'] = [[None, None, None, None, None, None, GREY, None, None],
                    [None, None, None, None, None, GREY, GREY, GREY, None],
                    [None, None, None, GREY, None, GREY, GREY, GREY, None],
                    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, BLUE, GREY, GREY, GREY],
                    [None, GREY, BLUE, GREY, BLUE, None, None, GREY, BLUE],
                    [BLUE, None, None, None, None, BLUE, None, None, None],
                    [None, BLUE, None, BLUE, None, None, BLUE, None, BLUE]]

# Light snow
ICONS['light_s'] = [[None, None, None, None, None, None, GREY, None, None],
                    [None, None, None, None, None, GREY, GREY, GREY, None],
                    [None, None, None, GREY, None, GREY, GREY, GREY, None],
                    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
                    [None, GREY, None, GREY, None, None, None, GREY, None],
                    [WHIT, None, None, None, None, WHIT, None, None, None],
                    [None, None, None, WHIT, None, None, None, None, WHIT]]

# Snow
ICONS['heavy_s'] = [[None, None, None, None, None, None, GREY, None, None],
                    [None, None, None, None, None, GREY, GREY, GREY, None],
                    [None, None, None, GREY, None, GREY, GREY, GREY, None],
                    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
                    [GREY, GREY, GREY, GREY, GREY, WHIT, GREY, GREY, GREY],
                    [None, GREY, WHIT, GREY, WHIT, None, None, GREY, WHIT],
                    [WHIT, None, None, None, None, WHIT, None, None, None],
                    [None, WHIT, None, WHIT, None, None, WHIT, None, WHIT]]

class Meteo(app.BaseApplication):
    """Class for displaying meteo informations."""

    def show_temp(self, temp):
        """Show the temperature."""
        self._grid.draw_char(4, 2, temp[0], (100, 100, 255))
        self._grid.draw_char(4, 6, temp[1], (100, 100, 255))
        self._grid.draw_point(3, 10, (100, 100, 255))
        self._grid.show()

    def show_icon(self):
        """Show the icon."""
        self._grid.draw_subgrid(1, 1, ICONS['sunny'])


def demo():
    """Demo of the module."""
    g = grid.Grid(12, 12)
    for tpe in ICONS:
        g.draw_rectangle(0, 0, 11, 11, fill=(50, 50, 50))
        g.draw_subgrid(1, 1, ICONS[tpe])
        g.show()

    Meteo().show_temp()

if __name__ == '__main__':
    demo()
