# -*- coding: utf-8 -*-
"""Project configuration."""

# --------------------------------------------------------------------------- #
# Configuration variables                                                     #
# --------------------------------------------------------------------------- #

DEBUG = True
"""Debug mode."""

LANG = 'en'
"""The langage to use in the application.

Possibles values are 'en', 'fr' or 'de'.

"""

IS_WIPY = None
"""Specify if the platform running the code is the Wipy.

Set it to None for auto-detection.

"""

HAS_XTERMCOLOR = None
"""Specify if the xtermcolor package is installed.

Set it to None for auto-detection.

"""

DIGITS_SUPPORT = True
"""Specify if digits ([0-9]) should be supported.

Set it to None for auto-detection.

"""

LETTERS_SUPPORT = None
"""Specify if letters ([A-Z]) should be supported.

Set it to None for auto-detection.

"""


# --------------------------------------------------------------------------- #
# Automatically detected variables                                            #
# --------------------------------------------------------------------------- #

# Autodectect IS_WIPY
if IS_WIPY is None:
    try:
        # If we can import the importlib module, we are NOT on the Wipy
        # pylint: disable=unused-import
        import importlib  # NOQA
        IS_WIPY = False
    except ImportError:
        IS_WIPY = True

# Autodectect HAS_XTERMCOLOR
if HAS_XTERMCOLOR is None:
    if IS_WIPY:
        HAS_XTERMCOLOR = False
    else:
        try:
            XTERMCOLOR = importlib.util.find_spec("xtermcolor")
            HAS_XTERMCOLOR = XTERMCOLOR is not None
            del XTERMCOLOR
        except ImportError:
            HAS_XTERMCOLOR = False


# Autodectect DIGITS_SUPPORT
if DIGITS_SUPPORT is None:
    DIGITS_SUPPORT = not IS_WIPY

# Autodectect LETTERS_SUPPORT
if LETTERS_SUPPORT is None:
    LETTERS_SUPPORT = not IS_WIPY
