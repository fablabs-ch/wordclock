# -*- coding: utf-8 -*-
"""English language support."""


class WordClockLang():
    """WordClock language support."""

    # The word grid, used for terminal display
    word_grid = [["V", "I", "T", "K", "I", "S", "W", "H", "A", "L", "F", "I"],
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


    def time_to_leds(self, hours, minutes, seconds):
        """Return the LEDS corresponting to the given time."""
        leds = list()

        # it
        leds += [(0, 1), (0, 2)]

        # is
        leds += [(0, 4), (0, 5)]

        # hours
        if minutes > 30:
            hours += 1

        if hours in [0, 24]:
            leds += [(7, 6), (7, 7), (7, 8), (7, 9), (7, 10), (7, 11)]
        elif hours in [1, 13]:
            leds += [(3, 8), (3, 9), (3, 10)]
        elif hours in [2, 14]:
            leds += [(4, 0), (4, 1), (4, 2)]
        elif hours in [3, 15]:
            leds += [(4, 3), (4, 4), (4, 5), (4, 6), (4, 7)]
        elif hours in [4, 16]:
            leds += [(4, 8), (4, 9), (4, 10), (4, 11)]
        elif hours in [5, 17]:
            leds += [(5, 0), (5, 1), (5, 2), (5, 3)]
        elif hours in [6, 18]:
            leds += [(5, 4), (5, 5), (5, 6)]
        elif hours in [7, 19]:
            leds += [(5, 7), (5, 8), (5, 9), (5, 10), (5, 11)]
        elif hours in [8, 20]:
            leds += [(6, 0), (6, 1), (6, 2), (6, 3), (6, 4)]
        elif hours in [9, 21]:
            leds += [(6, 5), (6, 6), (6, 7), (6, 8)]
        elif hours in [10, 22]:
            leds += [(6, 9), (6, 10), (6, 11)]
        elif hours in [11, 23]:
            leds += [(7, 0), (7, 1), (7, 2), (7, 3), (7, 4), (7, 5)]

        # minutes
        rest = minutes % 5
        minutes = minutes // 5

        if minutes == 0:
            # oclock
            leds += [(8, 3), (8, 4), (8, 5),
                     (8, 6), (8, 7), (8, 8)]  # oclock
        elif minutes == 1:
            leds += [(2, 8), (2, 9), (2, 10), (2, 11)]  # five
            leds += [(3, 0), (3, 1), (3, 2), (3, 3)]  # past
        elif minutes == 2:
            leds += [(1, 0), (1, 1), (1, 2)]  # ten
            leds += [(3, 0), (3, 1), (3, 2), (3, 3)]  # past
        elif minutes == 3:
            leds += [(1, 3), (1, 5), (1, 6), (1, 7),
                     (1, 8), (1, 9), (1, 10), (1, 11)]  # a quarter
            leds += [(3, 0), (3, 1), (3, 2), (3, 3)]  # past
        elif minutes == 4:
            leds += [(2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6)]  # twenty
            leds += [(3, 0), (3, 1), (3, 2), (3, 3)]  # past
        elif minutes == 5:
            leds += [(2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6)]  # twenty
            leds += [(2, 7)]
            leds += [(2, 8), (2, 9), (2, 10), (2, 11)]  # five
            leds += [(3, 0), (3, 1), (3, 2), (3, 3)]  # past
        elif minutes == 6:
            leds += [(0, 7), (0, 8), (0, 9), (0, 10)]  # half
            leds += [(3, 0), (3, 1), (3, 2), (3, 3)]  # past
        elif minutes == 7:
            leds += [(2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6)]  # twenty
            leds += [(2, 7)]
            leds += [(2, 8), (2, 9), (2, 10), (2, 11)]  # five
            leds += [(3, 5), (3, 6)]  # to
        elif minutes == 8:
            leds += [(2, 1), (2, 2), (2, 3), (2, 4), (2, 5), (2, 6)]  # twenty
            leds += [(3, 5), (3, 6)]  # to
        elif minutes == 9:
            leds += [(1, 3), (1, 5), (1, 6), (1, 7),
                     (1, 8), (1, 9), (1, 10), (1, 11)]  # a quarter
            leds += [(3, 5), (3, 6)]  # to
        elif minutes == 10:
            leds += [(1, 0), (1, 1), (1, 2)]  # ten
            leds += [(3, 5), (3, 6)]  # to
        elif minutes == 11:
            leds += [(2, 8), (2, 9), (2, 10), (2, 11)]  # five
            leds += [(3, 5), (3, 6)]  # to

        if rest == 4:
            if seconds % 2:
                leds += [(10, 4), (10, 5), (10, 6), (10, 7)]
        if rest != 4:
            for i in range(rest + (seconds % 2)):
                leds += [(10, 4 + i)]

        return leds
