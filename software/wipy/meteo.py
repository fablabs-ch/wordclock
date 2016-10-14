# -*- coding: utf-8 -*-
"""Meteo application."""

import app

# Colors abbreviation in 4 letters, for ICONS definitions alignment
YELL = (255, 200, 100)
GREY = (150, 150, 150)
BLUE = (50, 50, 255)
WHIT = (255, 255, 255)

# Meteo icons
ICONS = dict()

ICONS['sunny'] = [
    [None, None, None, None, YELL, None, None, None, None],
    [None, YELL, None, None, YELL, None, None, YELL, None],
    [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
    [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
    [YELL, YELL, YELL, YELL, YELL, YELL, YELL, YELL, YELL],
    [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
    [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
    [None, YELL, None, None, YELL, None, None, YELL, None],
    [None, None, None, None, YELL, None, None, None, None]]

ICONS['mostly_sunny'] = [
    [None, None, None, None, YELL, None, None, None, None],
    [None, YELL, None, None, YELL, None, None, None, None],
    [None, None, YELL, YELL, YELL, YELL, GREY, None, None],
    [None, None, YELL, YELL, YELL, GREY, GREY, GREY, None],
    [YELL, YELL, YELL, GREY, YELL, GREY, GREY, GREY, None],
    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
    [None, GREY, None, GREY, None, None, None, GREY, None]]


ICONS['partial_sunny'] = [
    [None, None, None, None, YELL, None, None, None, None],
    [None, YELL, None, None, YELL, None, None, YELL, None],
    [None, None, YELL, YELL, YELL, YELL, YELL, None, None],
    [None, None, YELL, YELL, YELL, YELL, YELL, GREY, None],
    [YELL, YELL, YELL, YELL, YELL, YELL, GREY, GREY, None],
    [None, None, YELL, YELL, YELL, GREY, GREY, GREY, GREY],
    [None, None, YELL, YELL, YELL, GREY, GREY, GREY, GREY],
    [None, YELL, None, None, GREY, None, GREY, GREY, GREY],
    [None, None, None, None, None, None, None, GREY, None]]

ICONS['cloudy'] = [
    [None, None, None, None, None, None, None, None, None],
    [None, None, None, None, None, None, GREY, None, None],
    [None, None, None, None, None, GREY, GREY, GREY, None],
    [None, None, None, GREY, None, GREY, GREY, GREY, None],
    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
    [None, GREY, None, GREY, None, None, None, GREY, None],
    [None, None, None, None, None, None, None, None, None]]

ICONS['light_rain'] = [
    [None, None, None, None, None, None, GREY, None, None],
    [None, None, None, None, None, GREY, GREY, GREY, None],
    [None, None, None, GREY, None, GREY, GREY, GREY, None],
    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
    [None, GREY, None, GREY, None, None, None, GREY, None],
    [BLUE, None, None, None, None, BLUE, None, None, None],
    [None, None, None, BLUE, None, None, None, None, BLUE]]

ICONS['heavy_rain'] = [
    [None, None, None, None, None, None, GREY, None, None],
    [None, None, None, None, None, GREY, GREY, GREY, None],
    [None, None, None, GREY, None, GREY, GREY, GREY, None],
    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, BLUE, GREY, GREY, GREY],
    [None, GREY, BLUE, GREY, BLUE, None, None, GREY, BLUE],
    [BLUE, None, None, None, None, BLUE, None, None, None],
    [None, BLUE, None, BLUE, None, None, BLUE, None, BLUE]]

ICONS['light_snow'] = [
    [None, None, None, None, None, None, GREY, None, None],
    [None, None, None, None, None, GREY, GREY, GREY, None],
    [None, None, None, GREY, None, GREY, GREY, GREY, None],
    [None, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY, GREY],
    [GREY, GREY, GREY, GREY, GREY, None, GREY, GREY, GREY],
    [None, GREY, None, GREY, None, None, None, GREY, None],
    [WHIT, None, None, None, None, WHIT, None, None, None],
    [None, None, None, WHIT, None, None, None, None, WHIT]]

ICONS['heavy_snow'] = [
    [None, None, None, None, None, None, GREY, None, None],
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
        # Initialize variables
        shift = 0
        neg = False
        # Check if temperature is negative
        if temp < 0:
            neg = True
            temp = abs(temp)
        # Transform temprature to int
        digits = str(temp)
        if len(digits) == 1:
            if neg:
                # Draw the minus signe before
                self._grid.draw_char(4, 2, '-', (100, 100, 255))
                shift += 1
            # Draw the first character
            self._grid.draw_char(4, 5, digits[0], (100, 100, 255))
            # Draw the degree square
            self._grid.draw_point(3, 9, (100, 100, 255))
        else:
            if neg:
                # Draw the minus signe before
                self._grid.draw_char(4, 0, '-', (100, 100, 255))
                shift += 1
            # Draw the first character
            self._grid.draw_char(4, 2 + shift, digits[0], (100, 100, 255))
            # Draw the second if existing
            self._grid.draw_char(4, 6 + shift, digits[1], (100, 100, 255))
            # Draw the degree square
            self._grid.draw_point(3, 10 + shift, (100, 100, 255))
            # Draw the degree square
            self._grid.draw_point(3, 10 + shift, (100, 100, 255))
        # Show it
        self._grid.show()

    def show_icon(self, weather):
        """Show the weather icon."""
        self._grid.draw_subgrid(1, 1, ICONS[weather])
        # Show it
        self._grid.show()


def demo():
    """Demo of the module."""
    Meteo().show_temp(-12)
    Meteo().show_icon('sunny')


if __name__ == '__main__':
    demo()
