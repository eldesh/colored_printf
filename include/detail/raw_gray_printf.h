#if !defined RAW_GRAY_PRINTF_INCLUDED
#define      RAW_GRAY_PRINTF_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

/**
 * \pre fr_gray < 24
 * \pre bk_gray < 24
 */

void set_gray (FILE * fp, uint8_t fr_gray, uint8_t bk_gray);
int vfprintf_gray (uint8_t fr_gray, uint8_t bk_gray, FILE * fp, char const * format, va_list ap);
int fprintf_gray (uint8_t fr_gray, uint8_t bk_gray, FILE * fp, char const * format, ...);
int printf_gray (uint8_t fr_gray, uint8_t bk_gray, char const * format, ...);

#endif    /* RAW_GRAY_PRINTF_INCLUDED */

