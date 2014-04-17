
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

*make -C sample* would build the sample program *sample/colorspace-sample* .
This sample output color chart.


How to Use
---------------------------------------------------------------

see sample/colorspace-sample.c :)


Main API
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

.. c:function:: int fprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, ...)

       output fore&back ground colored string


Example
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

for example, you can accentuate error messages like below:

.. code-block:: c

    uint8_t    const white = 255;
    color216_t const   red = make_color216_t(5,0,0);
    fprintf_256colored(white, red, stdout
                      , "[ERROR] no such file or directory (%s)"
                      , path_to_dir);

then, users would see the red-colored error message.

Requirements
---------------------------------------------------------------

.. [#ansi] http://en.wikipedia.org/wiki/ANSI_escape_code
