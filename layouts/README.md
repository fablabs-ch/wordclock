# Layouts

This page describes the different available layouts with their specificity, and
the tools that can be used to work with them.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-generate-toc again -->
**Table of Contents**

- [Layouts](#layouts)
    - [Available layouts](#available-layouts)
        - [French](#french)
        - [English](#english)
        - [Holes](#holes)
    - [Tools](#tools)
        - [Raw format](#raw-format)
        - [SVG generation script](#svg-generation-script)
        - [Inkscape](#inkscape)

<!-- markdown-toc end -->

## Generated layouts

The layouts proposed below have their generated `*.svg` proposed in the
`generated` folder. The font used in these documents is "Glaser Beckes Stencil"
available for download
[here](http://ufonts.com/fonts/glaser-becker-stencil.html).

## Available layouts

Two layout are available for now: French and English. Each layout is shown
below, and it's accessible in a [raw format](#raw-format) in the `raw/` folder.

### French

|        | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 |
|:------:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
| **01** | I  | L  |    |    | E  | S  | T  |    |    | U  | N  | E  |
| **02** | T  | R  | O  | I  | S  |    | Q  | U  | A  | T  | R  | E  |
| **03** | C  | I  | N  | Q  | S  | I  | X  |    | S  | E  | P  | T  |
| **04** | H  | U  | I  | T  |    | N  | E  | U  | F  | D  | I  | X  |
| **05** |    | O  | N  | Z  | E  |    | D  | O  | U  | Z  | E  |    |
| **06** |    |    | D  | E  | U  | X  |    | H  | E  | U  | R  | E  |
| **07** | M  | O  | I  | N  | S  |    | E  | T  |    | D  | I  | X  |
| **08** |    |    | V  | I  | N  | G  | T  | -  | C  | I  | N  | Q  |
| **09** | Q  | U  | A  | R  | T  |    | D  | E  | M  | I  |    |    |
| **10** |    |    |    |    |    |    |    |    |    |    |    |    |
| **11** |    |    |    |    | *  | *  | *  | *  |    |    |    |    |
| **12** |    |    |    |    |    |    |    |    |    |    |    |    |

Specificity:

- 12 * 12 = 144 LEDs
- Letters missing from the layout: BJKWY

### English

|        | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 |
|:------:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
| **01** |    | I  | T  |    | I  | S  |    | H  | A  | L  | F  |    |
| **02** | T  | E  | N  | A  |    | Q  | U  | A  | R  | T  | E  | R  |
| **03** |    | T  | W  | E  | N  | T  | Y  | -  | F  | I  | V  | E  |
| **04** | P  | A  | S  | T  |    | T  | O  |    | O  | N  | E  |    |
| **05** | T  | W  | O  | T  | H  | R  | E  | E  | F  | O  | U  | R  |
| **06** | F  | I  | V  | E  | S  | I  | X  | S  | E  | V  | E  | N  |
| **07** | E  | I  | G  | H  | T  | N  | I  | N  | E  | T  | E  | N  |
| **08** | E  | L  | E  | V  | E  | N  | T  | W  | E  | L  | V  | E  |
| **09** |    |    |    | O  | C  | L  | O  | C  | K  |    |    |    |
| **10** |    |    |    |    |    |    |    |    |    |    |    |    |
| **11** |    |    |    |    | *  | *  | *  | *  |    |    |    |    |
| **12** |    |    |    |    |    |    |    |    |    |    |    |    |

Specificity:

- 12 * 12 = 144 LEDs
- Letters missing from the layout: BDJMZ

### Holes

The layouts have been designed to maximize the distribution of the holes across
the whole grid. The holes in the table later can be:

- Left empty
- Replaced by symbols (weather, day/night, lunar cycle, seasons, etc.)
- Replaced by random letters

*Note:* It could be interesting to add the letters missing from the layout in
the holes, as it will allow to make the clock to talk by spelling out words.

## Tools

In order to work with layouts more effectively, a format has been defined to
work with a script that helps to generate the drawing of the layout.

### Raw format

The raw layouts for the available layouts are under the `raw/` folder. This
format is used to make the creation of scripts that work with the layout easier.
The format is simple, as shown here for the English layout:

```text
|   | I | T |   | I | S |   | H | A | L | F |   |
| T | E | N | A |   | Q | U | A | R | T | E | R |
|   | T | W | E | N | T | Y | - | F | I | V | E |
| P | A | S | T |   | T | O |   | O | N | E |   |
| T | W | O | T | H | R | E | E | F | O | U | R |
| F | I | V | E | S | I | X | S | E | V | E | N |
| E | I | G | H | T | N | I | N | E | T | E | N |
| E | L | E | V | E | N | T | W | E | L | V | E |
|   |   |   | O | C | L | O | C | K |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   | * | * | * | * |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |   |
```

It consists of vertical bars (`|`) separating the letters (`[A-Z]`). The number
of rows and columns is free as long as the layout is a rectangle (i.e. always
the same number of columns in all rows).

To customize your wordclock, you can create your own raw layout before using the
SVG generation script.

### SVG generation script

A tool is provided to generate the SVG of a given raw layout: `generate_svg.py`.
This permits to simplify the creation of the model in order to make the vinyl.

The usage is simply:

    ./generate_svg.py <filename>

where filename is the path to a raw layout file. For instance you can try:

    ./generate_svg.py raw/en.txt

There is also options to change the size (in mm) and style of the drawing, they
are described in the help message that can be shown with:

    ./generate_svg.py -h

Some parameters that can be modified are:

- The horizontal spacing of the letters (in mm)
- The vertical spacing of the letters (in mm)
- The horizontal margins of the drawing (in mm)
- The vertical margins of the drawing (in mm)
- The font size of the letters (in mm)
- The font family of the letters
- The font weight of the letters
- The output file

### Inkscape

Once the SVG has been generated, you can open it and edit it with [Inkscape][].
This let you adapt the colors, strokes style and all other parameters of the
drawing. It is also with Inkscape that you can modify the drawing to have some
letters that span on multiple rows/columns, like for instance the big `JAVELIN`
that is written on the Javelin's wordclock:

![wordclock](http://cdn.instructables.com/FDZ/AQD1/HZTO8RV9/FDZAQD1HZTO8RV9.LARGE.jpg)

[Inkscape]: https://inkscape.org/en/
