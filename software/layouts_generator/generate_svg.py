#!/usr/bin/env python
"""Generate the SVG drawing for a given wordclock's layout.

This file is part of the fablabs-ch wordclock project:
https://github.com/fablabs-ch/wordclock

This file is licensed under the MIT license:

===============================================================================
The MIT License (MIT)

Copyright (c) 2015 Fabien Dubosson <fabien.dubosson@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS IMPLIED
OR, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR
A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
===============================================================================

"""

import argparse
import csv
import os
import sys
import random
import tempfile

from shlex import split
from subprocess import check_output
from subprocess import CalledProcessError

MM_TO_PX_RATIO = 3.543307


# pylint: disable=unused-argument
def generate_svg(width, height, content):
    """Generate a SVG drawing.

    Args:
        width (float): The width of the drawing (in mm).
        height (float): The height of the drawing (in mm).
        content (str): The content of the drawing.

    Returns:
        str: The SVG drawing.

    """
    # Return the template formated with the variables defined in this function
    return SVG_TEMPLATE.format(**locals())


# pylint: disable=unused-argument,too-many-arguments,
def generate_letter(x, y, font_size, baseline_height, letter,
                    font_family='Arial',
                    font_weight='normal',
                    stroke='black',
                    stroke_width=0.5,
                    fill='none'):
    """Generate a SVG letter.

    Args:
        x (float): The x position of the letter (in mm).
        y (float): The y position of the letter (in mm).
        font_size (float): The font size (in mm).
        baseline_height (float): The real height of the letter (in mm).
        letter (chr): The letter.
        font_family (Optional str): The font family (default: Arial).
        font_weight (Optional str): The font weight (default: normal).
        stroke (Optional str): The stroke color (default: black).
        stroke_width (Optional float): The stroke width (default: 0.5, in mm).
        fill (Optional str): The fill color (default: none)

    Returns:
        str: The SVG representation of the letter.

    """
    # Shift the letter in the `y` direction to center it
    dy = font_size / 2  # pylint: disable=unused-variable,invalid-name
    # Correct the fontsize so that letter height are really what is passed as
    # `font_size`
    font_size *= font_size / baseline_height
    # Return the template formated with the variables defined in this function
    return LETTER_TEMPLATE.format(**locals())


# pylint: disable=unused-argument,too-many-arguments
def generate_rect(x, y, width, height,
                  stroke='black',
                  stroke_width=0.5,
                  fill='none'):
    """Generate a SVG rectangle.

    Args:
        x (float): The x position of the rectangle (in mm).
        y (float): The y position of the rectangle (in mm).
        width (float): The width of the rectangle (in mm).
        height (float): The height of the rectangle (in mm).
        stroke (Optional str): The stroke color (default: black).
        stroke_width (Optional float): The stroke width (default: 0.5, in mm).
        fill (Optional str): The fill color (default: none)

    Returns:
        str: The SVG representation of the rectangle.

    """
    # Return the template formated with the variables defined in this function
    return RECT_TEMPLATE.format(**locals())


def compute_baseline_height(font_size, font_family, font_weight,
                            stroke_width=0.5):
    """Compute the baseline height of a given font specification.

    Args:
        font_size (float): The font size (in mm).
        font_family (str): The font family.
        font_weight (str): The font weight.
        stroke_width (Optional float): The stroke width (default: 0.5, in mm).

    Returns:
        float: The baseline height of the font (in mm).

    """
    # Initialize variables
    props = None
    # Generate a SVG letter to compute baseline height
    with tempfile.NamedTemporaryFile() as temp:
        # Generate a SVG letter
        letter = generate_letter(0, 0, font_size, font_size, 'W',
                                 font_family=font_family,
                                 font_weight=font_weight,
                                 stroke_width=stroke_width)
        svg = generate_svg(10, 10, letter)
        temp.file.write(svg.encode('utf8'))
        temp.file.flush()
        # Call inkscape to get properties
        try:
            cmd = split("inkscape --query-all {}".format(temp.name))
            props = check_output(cmd)
            props = props.decode('utf8').strip().split('\n')
            props = list(csv.reader(props))
        # Deal with errors
        except CalledProcessError:
            print("There was a problem whan calling 'inkscape'.")
            sys.exit(1)
    # If no props, an error occured
    if props is None:
        print("There was a problem with baseline computation.")
        sys.exit(1)
    # Get the tspan properties
    height = float([r for r in props if r[0][:5] == "tspan"][0][4])
    # Returns the baseline height
    return height / MM_TO_PX_RATIO


def args_parser():
    """Return the parser for command line arguments.

    Returns:
        argparse.ArgumentParser: The parser.

    """
    # Prepare the parser
    parser = argparse.ArgumentParser(
        description='Generate the SVG drawing of a given wordclock''s layout.',
        add_help=False)
    # Add flags
    flags = parser.add_argument_group("Flags")
    flags.add_argument('--debug', '-d',
                       action='store_true', default=False,
                       help='enable debug mode.')
    # Add parameters
    params = parser.add_argument_group("Parameters")
    params.add_argument('--hs',
                        type=float, default=10,
                        help='horizontal spacing of the letters (in mm)')
    params.add_argument('--vs',
                        type=float, default=10,
                        help='vertical spacing of the letters (in mm)')
    params.add_argument('--hm',
                        type=float, default=10,
                        help='horizontal margins of the drawing (in mm)')
    params.add_argument('--vm',
                        type=float, default=10,
                        help='vertical margins of the drawing (in mm)')
    params.add_argument('--fs',
                        type=float, default=8,
                        help='font size of the letters (in mm)')
    params.add_argument('--ff',
                        type=str, default="",
                        help='font family of the letters')
    params.add_argument('--fw',
                        type=str, default="",
                        help='font weight of the letters')
    params.add_argument('--output', '-o',
                        type=str, default="generated.svg",
                        help='output file')
    # Positional arguments
    params.add_argument('filename', metavar="FILENAME",
                        help='name of the text file containing the layout')
    # Add the help group with help entry
    helpgroup = parser.add_argument_group("Help")
    helpgroup.add_argument('--help', '-h',
                           action='help',
                           help='show this help message and exit')
    # Return the parser
    return parser


def generate(grid, conf):
    """Generate the layout.

    Args:
        grid: (List of List of str): The grid to generate.
        conf (argparse.Namespace): Configuration parameters for the grid.

    Returns:
        str: The SVG representation of the generated grid.
    """
    # Compute the baseline height
    baseline_height = compute_baseline_height(conf.fs, conf.ff, conf.fw)
    # Initialize the letters and rects sections
    letters = ""
    rects = "<g>\n"
    # Iterate over the grid
    num_y, num_x = len(grid), len(grid[0])
    for y, row in enumerate(grid):
        for x, char in enumerate(row):
            # If the character is a whitespace, put a random character instead
            char = char.strip()
            if not char:
                char = chr(random.randint(0, 25) + 65)
            # Generate and add the SVG of the character
            letters += generate_letter(
                x=conf.hm + conf.hs / 2 + x * conf.hs,
                y=conf.vm + conf.vs / 2 + y * conf.vs,
                font_size=conf.fs,
                baseline_height=baseline_height,
                letter=char,
                font_family=conf.ff, font_weight=conf.fw,
                fill="white", stroke="none", stroke_width=0)
            # Generate and add the SVG bounding rectangle
            rects += generate_rect(x=conf.hm + x * conf.hs,
                                   y=conf.vm + y * conf.vs,
                                   width=conf.hs, height=conf.vs,
                                   stroke='red')
    # Close the rectangle section
    rects += "</g>"
    # Generate the frame
    frame = generate_rect(0, 0,
                          width=num_x * conf.hs + 2 * conf.hm,
                          height=num_y * conf.vs + 2 * conf.vm,
                          stroke="none", stroke_width=0, fill="#231f20")
    # Compose the SVG out of the frame, letters and rectangles
    svg = generate_svg(width=num_x * conf.hs + 2 * conf.hm,
                       height=num_y * conf.vs + 2 * conf.vm,
                       content=frame + letters + rects)
    # Return the SVG
    return svg


def main():
    """Entry point of the script."""
    # Parse command line arguments
    args = args_parser().parse_args()
    # Verify the input file exists
    if not os.path.isfile(args.filename):
        print("The passed file doesn't exists.")
        sys.exit(1)
    # Read the grid
    with open(args.filename) as csvfile:
        lines = csvfile.readlines()
    # Transform the grid to an usable format
    grid = [[c for c in line.strip('\n')] for line in lines]
    # Generate the SVG
    svg = generate(grid, args)
    # Save the SVG
    with open(args.output, 'w') as out:
        print(svg, file=out)


SVG_TEMPLATE = r'''<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<svg xmlns="http://www.w3.org/2000/svg"
     width="{width}mm"
     height="{height}mm">
{content}
</svg>
'''
"""SVG file template."""

LETTER_TEMPLATE = r'''
<text x="{x}mm"
      y="{y}mm"
      text-anchor="middle"
      font-size="{font_size}mm"
      font-family="{font_family}"
      font-weight="{font_weight}"
      stroke="{stroke}"
      stroke-width="{stroke_width}mm"
      fill="{fill}"><tspan dy="{dy}mm">{letter}</tspan></text>
'''
"""SVG letter template."""

RECT_TEMPLATE = r'''
<rect x="{x}mm"
      y="{y}mm"
      width="{width}mm"
      height="{height}mm"
      stroke="{stroke}"
      stroke-width="{stroke_width}mm"
      fill="{fill}"/>
'''
"""SVG rectangle template."""


# If called from the command line, run the script
if __name__ == '__main__':
    main()
