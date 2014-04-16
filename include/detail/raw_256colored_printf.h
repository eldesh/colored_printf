#if !defined RAW_256COLORED_PRINTF_INCLUDED
#define      RAW_256COLORED_PRINTF_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint8_t color216_t;
uint8_t color216_red  (color216_t color);
uint8_t color216_green(color216_t color);
uint8_t color216_blue (color216_t color);

typedef uint8_t color256_t;
int start_256color_foreground(FILE * fp, color256_t color);
int start_256color_background(FILE * fp, color256_t color);

int vfprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, va_list ap);
int fprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, ...);
int printf_256colored(color256_t fr_color, color256_t bk_color, char const * format, ...);

#endif    /* RAW_256COLORED_PRINTF_INCLUDED */

