# -*- coding: utf-8 -*-
"""Base application module."""

from grid import Grid


class BaseApplication():
    """Base class for Applications."""

    def __init__(self):
        """Create a base application."""
        self._grid = Grid(12, 12)

    def run(self):
        """Coroutine that run application."""
        raise NotImplementedError()
