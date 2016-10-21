#!/usr/bin/env python
"""Serve the SVG generator as an HTTP service.

The Flask server is not directly integrated within the main file because it
requires additional dependencies that are not needed for using the file
locally.

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

import flask
import generate_svg


APP = flask.Flask(__name__)

PARAMS = [('hs', 'Horizontal spacing of the letters (in mm):', 10, 'number'),
          ('vs', 'Vertical spacing of the letters (in mm):', 10, 'number'),
          ('hm', 'Horizontal margins of the drawing (in mm):', 10, 'number'),
          ('vm', 'Vertical margins of the drawing (in mm):', 10, 'number'),
          ('fs', 'Font size of the letters (in mm):', 8, 'number'),
          ('ff', 'Font family of the letters:', '', 'text'),
          ('fw', 'Font weight of the letters:', '', 'text')]


@APP.route('/')
def index():
    """Index page."""
    return flask.render_template('index.html', params=PARAMS)


@APP.route('/generate-layout/', methods=['POST'])
def generate_layout():
    """Generate the SVG layout."""
    # Simulate parsing configuration to get default values
    conf = generate_svg.args_parser().parse_args([''])
    # Get parameters
    for param in PARAMS:
        val = flask.request.form[param[0]]
        if param[3] == 'number':
            val = int(val)
        conf.__setattr__(param[0], val)
    print(conf)
    # Get the grid
    grid = flask.request.form['grid'].strip()
    # Build the SVG
    try:
        svg = generate_svg.generate(grid, conf)
    # pylint: disable=bare-except
    except:
        return flask.render_template('error.html',
                                     msg='Impossible to generate the SVG.')
    else:
        # Prepare and return the response
        resp = flask.Response(svg)
        resp.headers['Content-Type'] = 'image/svg+xml'
        resp.headers['Content-Disposition'] = 'attachment; ' \
                                              'filename=generated.svg'
        resp.headers['Pragma'] = 'no-cache'
    # Return the response
    return resp


def main():
    """Entry point of the program."""
    APP.run(port=8000, debug=True)


if __name__ == '__main__':
    main()
