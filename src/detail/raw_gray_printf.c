#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "detail/raw_colored_printf.h"
#include "detail/raw_256colored_printf.h"
#include "detail/raw_gray_printf.h"

void start_gray (FILE * fp, uint8_t fr_gray, uint8_t bk_gray) {
	assert(fr_gray < 24);
	assert(bk_gray < 24);
	fprintf_qualify(fp, TERMINAL_BK_256COLOR_TEXT);
	fprintf_qualify(fp, TEXT_ATTR_BLINK);
	fprintf_qualify(fp, 232+fr_gray);
	fprintf_qualify(fp, 232+bk_gray);
}

int fprintf_gray (FILE * fp, uint8_t fr_gray, uint8_t bk_gray, char const * format, ...) {
	assert(fr_gray < 24);
	assert(bk_gray < 24);
	{
		int r;
		va_list ap;
		va_start(ap, format);
		start_gray(fp, fr_gray, bk_gray);
		r = vfprintf(fp, format, ap);
		fprintf_qualify(fp, TEXT_ATTR_OFF);
		va_end(ap);
		return r;
	}
}

