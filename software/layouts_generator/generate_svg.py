#!/usr/bin/env python
"""
Generate the SVG drawing for a given wordclock's layout.

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


def generate_svg(width, height, content):
    # pylint: disable=unused-argument
    """
    Generate a SVG drawing.

    Args:
        width (float): The width of the drawing (in mm).
        height (float): The height of the drawing (in mm).
        content (str): The content of the drawing.

    Returns:
        str: The SVG drawing.
    """
    # Return the template formated with the variables defined in this function
    return SVG_TEMPLATE.format(**locals())


def generate_letter(x, y, font_size, baseline_height, letter,
                    font_family='Arial',
                    font_weight='normal',
                    stroke='black',
                    stroke_width=0.5,
                    fill='none'):
    # pylint: disable=unused-argument,too-many-arguments,
    """
    Generate a SVG letter.

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


def generate_rect(x, y, width, height,
                  stroke='black',
                  stroke_width=0.5,
                  fill='none'):
    # pylint: disable=unused-argument,too-many-arguments
    """
    Generate a SVG rectangle.

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
    """
    Compute the baseline height of a given font specification.

    Args:

    Returns:
        float: The baseline height of the font (in mm).
    """
    #
    props = None
    with tempfile.NamedTemporaryFile() as temp:
        letter = generate_letter(0, 0, font_size, font_size, 'W',
                                 font_family=font_family,
                                 font_weight=font_weight,
                                 stroke_width=stroke_width)
        svg = generate_svg(10, 10, letter)
        temp.file.write(svg.encode('utf8'))
        temp.file.flush()
        try:
            cmd = split("inkscape --query-all {}".format(temp.name))
            props = check_output(cmd)
            props = props.decode('utf8').strip().split('\n')
            props = list(csv.reader(props))
        except CalledProcessError:
            print("There was a problem whan calling 'inkscape'.")
            sys.exit(1)
    if props is None:
        print("There was a problem with baseline computation.")
        sys.exit(1)
    # Get the tspan properties
    height = float([r for r in props if r[0][:5] == "tspan"][0][4])
    return height / MM_TO_PX_RATIO


def parse_args():
    """
    Parse command line arguments.

    Returns:
        argparse.Namespace: The parsed arguments.
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
                        type=str, default="out.svg",
                        help='output file')
    # Positional arguments
    params.add_argument('filename', metavar="FILENAME",
                        help='name of the text file containing the layout')
    # Add the help group with help entry
    helpgroup = parser.add_argument_group("Help")
    helpgroup.add_argument('--help', '-h',
                           action='help',
                           help='show this help message and exit')
    # Really parse the arguments
    return parser.parse_args()


def main():
    """Entry point of the script."""
    args = parse_args()
    if not os.path.isfile(args.filename):
        print("The given file doesn't exists.")
        sys.exit(1)
    # Baseline height
    baseline_height = compute_baseline_height(args.fs, args.ff, args.fw)
    # Read the grid
    grid = None
    with open(args.filename, newline='') as csvfile:
        grid = list(csv.reader(csvfile, delimiter='|'))
    # Prepare the content
    letters = ""
    rects = "<g>\n"
    num_y, num_x = len(grid), len(grid[0]) - 2  # Remove external "|"
    for y, row in enumerate(grid):
        for x, char in enumerate(row[1:-1]):
            character = char.strip()
            if not character:
                character = chr(random.randint(0, 25) + 65)
            letters += generate_letter(
                x=args.hm + args.hs / 2 + x * args.hs,
                y=args.vm + args.vs / 2 + y * args.vs,
                font_size=args.fs,
                baseline_height=baseline_height,
                letter=character,
                font_family=args.ff, font_weight=args.fw,
                fill="white", stroke="none", stroke_width=0)
            rects += generate_rect(x=args.hm + x * args.hs,
                                   y=args.vm + y * args.vs,
                                   width=args.hs, height=args.vs,
                                   stroke='red')
    rects += "</g>"
    frame = generate_rect(0, 0,
                          width=num_x * args.hs + 2 * args.hm,
                          height=num_y * args.vs + 2 * args.vm,
                          stroke="none", stroke_width=0, fill="#231f20")
    svg = generate_svg(width=num_x * args.hs + 2 * args.hm,
                       height=num_y * args.vs + 2 * args.vm,
                       content=frame + letters + rects)
    with open(args.output, 'w') as out:
        print(svg, file=out)


SVG_TEMPLATE = r'''<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<svg xmlns="http://www.w3.org/2000/svg"
     width="{width}mm"
     height="{height}mm">
{content}
</svg>
'''

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

RECT_TEMPLATE = r'''
<rect x="{x}mm"
      y="{y}mm"
      width="{width}mm"
      height="{height}mm"
      stroke="{stroke}"
      stroke-width="{stroke_width}mm"
      fill="{fill}"/>
'''

if __name__ == '__main__':
    main()
