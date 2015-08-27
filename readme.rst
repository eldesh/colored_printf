
ColoredPrintf
===============================================================

.. contents::

output colorized strings to your terminal like printf(3) family.


Requirements
---------------------------------------------------------------

need terminal pick out ANSI escape sequence. [#ansi]_


Build
---------------------------------------------------------------

just run *make* in top level directory of this library, then you will get *lib/libcolored-printf.a*.

*make sample* would build the sample programs *colorchart* and *show_ppm* .

colorchart
  display color chart.

show_ppm
  display PPM image.


How to Use
---------------------------------------------------------------

see sample/colorchart.c :)


Main API
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

.. c:function:: int fprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, ...)

       output fore&back ground colored string


Example
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

for example, you can accentuate error messages like below:

.. code-block:: c

    color256_t const white = color256_of_gray(23);
    color256_t const   red = color256_of_rgb(5,0,0);
    fprintf_256colored(white, red, stdout
                      , "[ERROR] no such file or directory (%s)"
                      , path_to_dir);

then, users would see the red-colored error message.

---------------------------------------------------------------

.. [#ansi] http://en.wikipedia.org/wiki/ANSI_escape_code

