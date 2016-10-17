# -*- coding: utf-8 -*-
"""Project configuration."""

# --------------------------------------------------------------------------- #
# Basic configuration                                                         #
# --------------------------------------------------------------------------- #

LANG = 'en'
"""The langage to use in the application.

Type: String

Possibles values are 'en', 'fr' or 'de'.

"""

CLOCK_COLOR = (255, 100, 255)
"""The default color of the wordclock.

Type: (Integer, Integer, Integer)

"""

NTP_SERVER = '0.ch.pool.ntp.org'
"""NTP server to use.

Type: String

"""

NTP_DELAY = 120
"""Time between two NTP synchronization.

Type: Integer

Time in second.

"""

TIME_SHIFT = 2 * 3600
"""The shift to apply on UTC time to get local time.

Type: Integer

Should be an integer, in second.

"""


# --------------------------------------------------------------------------- #
# Advanced configuration                                                      #
# --------------------------------------------------------------------------- #

DEBUG = False
"""Enable or disable debug output.

Type: Boolean

"""

IS_WIPY = None
"""Specify if the platform running the code is the Wipy.

Type: Boolean

Set it to None for auto-detection.

"""

HAS_XTERMCOLOR = None
"""Specify if the xtermcolor package is installed.

Type: Boolean

Set it to None for auto-detection.

"""

DIGITS_SUPPORT = True
"""Specify if digits ([0-9]) should be supported.

Type: Boolean

Set it to None for auto-detection.

"""

LETTERS_SUPPORT = True
"""Specify if letters ([A-Z]) should be supported.

Type: Boolean

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
