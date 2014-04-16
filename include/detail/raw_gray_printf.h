#if !defined RAW_GRAY_PRINTF_INCLUDED
#define      RAW_GRAY_PRINTF_INCLUDED

#include <stdlib.h>
#include <stdint.h>

/**
 * \pre fr_gray < 24
 * \pre bk_gray < 24
 */
int fprintf_gray (FILE * fp, uint8_t fr_gray, uint8_t bk_gray, char const * format, ...);

#endif    /* RAW_GRAY_PRINTF_INCLUDED */

