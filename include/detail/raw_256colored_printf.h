#if !defined RAW_256COLORED_PRINTF_INCLUDED
#define      RAW_256COLORED_PRINTF_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint8_t color256_t;

/**
 * \name constructor
 * @{
 */
/**
 * \pre
 *    color < 16
 */
color256_t color256_of_std (uint8_t color);
/**
 * \pre
 *    grapy < 24
 */
color256_t color256_of_gray(uint8_t gray);
/**
 * \pre
 *    r < 6
 *    g < 6
 *    b < 6
 */
color256_t color256_of_rgb (uint8_t r, uint8_t g, uint8_t b);
/** @} */

/**
 * \name accessor
 *
 * color256_red  (color256_of_rgb (r,?,?)) == r
 * color256_green(color256_of_rgb (?,g,?)) == g
 * color256_blue (color256_of_rgb (?,?,b)) == b
 * color256_gray (color256_of_gray(gray )) == gray
 * color256_std  (color256_of_std (color)) == color
 *
 * @{
 */
uint8_t color256_red  (color256_t color);
uint8_t color256_green(color256_t color);
uint8_t color256_blue (color256_t color);
uint8_t color256_gray (color256_t color);
uint8_t color256_std  (color256_t color);
/** @} */

int set_256color_foreground(FILE * fp, color256_t color);
int set_256color_background(FILE * fp, color256_t color);

int vfprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, va_list ap);
int fprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, ...);
int printf_256colored(color256_t fr_color, color256_t bk_color, char const * format, ...);

#endif    /* RAW_256COLORED_PRINTF_INCLUDED */

