#!/usr/bin/env python
# pylint: disable=bare-except
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

import os

import flask
import base64
from fontTools import ttLib
from werkzeug.utils import secure_filename

import generate_svg

FONT_SPECIFIER_NAME_ID = 4
FONT_SPECIFIER_FAMILY_ID = 1
UPLOAD_FOLDER = '/usr/share/fonts/truetype/'
ALLOWED_EXTENSIONS = set(['otf', 'ttf'])
PARAMS = [('hs', 'Horizontal spacing of the letters (in mm):', 16, 'number'),
          ('vs', 'Vertical spacing of the letters (in mm):', 16, 'number'),
          ('hm', 'Horizontal margin of the drawing (in mm):', 10, 'number'),
          ('vm', 'Vertical margin of the drawing (in mm):', 10, 'number'),
          ('ff', 'Desired font, default is Arial black (Will be used only to extract font-name and'
                 'compute cap-height of the font.):', '', 'file'),
          ('fs', 'Font size of the letters (in mm):', 8, 'number'),
          ('fw', 'Font weight of the letters: (e.g. "bold")', '', 'text')]

APP = flask.Flask(__name__)
APP.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
APP.config['MAX_CONTENT_LENGTH'] = 16 * 1024 * 1024


def allowed_file(filename):
    """Verify is the filename is allowed."""
    return '.' in filename and \
           filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS


def short_name(font):
    """Get the short name from the font's file.

    Taken from: https://gist.github.com/pklaus/dce37521579513c574d0

    """
    name = ""
    family = ""
    for record in font['name'].names:
        if b'\x00' in record.string:
            name_str = record.string.decode('utf-16-be')
        else:
            try:
                name_str = record.string.decode('utf-8')
            except UnicodeDecodeError:
                name_str = record.string.decode('iso8859-1')
        if record.nameID == FONT_SPECIFIER_NAME_ID and not name:
            name = name_str
        elif record.nameID == FONT_SPECIFIER_FAMILY_ID and not family:
            family = name_str
        if name and family:
            break
    return name, family


def handle_font():
    """Handle the posted font."""
    # check if the post flask.request has the file part
    if 'ff' not in flask.request.files:
        print('No file part, use default font')
        fullname = 'fonts/ariblk.ttf'
        print(fullname);
    else:
        file = flask.request.files['ff']
        # if user does not select file, browser also
        # submit a empty part without filename
        if file.filename == '':
            print('No selected file, use default font')
            fullname = 'fonts/ariblk.ttf'
            print(fullname);
        elif file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            fullname = os.path.join(APP.config['UPLOAD_FOLDER'], filename)
            file.save(fullname)
    font = ttLib.TTFont(fullname)
    print(short_name(font))
    return short_name(font)[1]


@APP.route('/')
def index():
    """Index page."""
    templates = [os.path.splitext(x)[0] for x in os.listdir('raw')]
    return flask.render_template('index.html',
                                 params=PARAMS,
                                 templates=templates)


@APP.route('/grid/<lang>')
def get_grid(lang):
    """Return existing grids."""
    return flask.send_from_directory('raw', lang + ".txt")

@APP.route('/script.js')
def get_script():
    return flask.render_template('script.js')

@APP.route('/preview')
def get_preview():
    username = request.args.get('username')
    password = request.args.get('password')

    resp = flask.Response(svg)
    resp.headers['Content-Type'] = 'image/svg+xml'
    resp.headers['Pragma'] = 'no-cache'
    # return flask.send_from_directory('./', "template.svg")

@APP.route('/generate-layout/', methods=['POST'])
def generate_layout():
    """Generate the SVG layout."""
    # Simulate parsing configuration to get default values
    conf = generate_svg.args_parser().parse_args([''])
    # Get parameters
    for param in [x for x in PARAMS if x[0] != 'ff']:
        if(param[0] in flask.request.form):
            val = flask.request.form[param[0]]
            if param[3] == 'number':
                val = int(val)
            conf.__setattr__(param[0], val)
    # Get font
    try:
        conf.ff = handle_font()
    except:
        return flask.render_template('error.html',
                                     msg='Problem with the provided font.')
    # Get the grid
    lines = flask.request.form['grid'].strip('\r\n').split('\r\n')
    grid = [[c for c in line.strip('\r\n')] for line in lines]
    # Build the SVG

    try:
        svg = generate_svg.generate(grid, conf)
    except:
        return flask.render_template('error.html',
                                     msg='Impossible to generate the SVG.')
    else:
        resp = flask.Response(svg)
        resp.headers['Content-Type'] = 'image/svg+xml'
        resp.headers['Content-Disposition'] = 'attachment; ' \
                                              'filename=generated.svg'
        resp.headers['Pragma'] = 'no-cache'
    # Return the response
    return resp


def main():
    """Entry point of the program."""
    APP.run(host='0.0.0.0', port=8000, debug=True)


if __name__ == '__main__':
    main()
