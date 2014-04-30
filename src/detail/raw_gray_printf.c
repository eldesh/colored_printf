#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "detail/raw_256colored_printf.h"
#include "detail/raw_gray_printf.h"

void set_gray (FILE * fp, uint8_t fr_gray, uint8_t bk_gray) {
	set_256color_foreground(fp, color256_of_gray(fr_gray));
	set_256color_background(fp, color256_of_gray(bk_gray));
}

int vfprintf_gray (uint8_t fr_gray, uint8_t bk_gray, FILE * fp, char const * format, va_list ap) {
	color256_t const fr = color256_of_gray(fr_gray);
	color256_t const bk = color256_of_gray(bk_gray);
	return vfprintf_256colored(fr, bk, fp, format, ap);
}

int fprintf_gray (uint8_t fr_gray, uint8_t bk_gray, FILE * fp, char const * format, ...) {
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf_gray(fr_gray, bk_gray, fp, format, ap);
	va_end(ap);
	return r;
}

int printf_gray (uint8_t fr_gray, uint8_t bk_gray, char const * format, ...) {
	int r;
	va_list ap;
	va_start(ap, format);
	r = fprintf_gray(fr_gray, bk_gray, stdout, format, ap);
	va_end(ap);
	return r;
}

