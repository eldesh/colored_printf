#include <stdio.h>
#include <assert.h>
#include "detail/raw_colored_printf.h"
#include "detail/raw_256colored_printf.h"

uint8_t color216_red  (color216_t color) {
	assert(16 <= color && color <= 16+216);
	return (color - 16) / 36;
}

uint8_t color216_green(color216_t color) {
	assert(16 <= color && color <= 16+216);
	return (color - 16) / 6;
}

uint8_t color216_blue (color216_t color) {
	assert(16 <= color && color <= 16+216);
	return (color - 16) / 1;
}

color216_t make_color216_t (uint8_t r, uint8_t g, uint8_t b) {
	assert(r < 6);
	assert(g < 6);
	assert(b < 6);
	return 16 + r*36 + g*6 + b;
}


int start_256color_foreground(FILE * fp, color256_t color) {
	return fprintf(fp, "\x1b[38;5;%dm", color);
}

int start_256color_background(FILE * fp, color256_t color) {
	return fprintf(fp, "\x1b[48;5;%dm", color);
}

int vfprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, va_list ap) {
	int r;
	start_256color_foreground(fp, fr_color);
	start_256color_background(fp, bk_color);
	r = vfprintf(fp, format, ap);
	fprintf_qualify(fp, TEXT_ATTR_OFF);
	return r;
}

int fprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, ...) {
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf_256colored(fr_color, bk_color, fp, format, ap);
	va_end(ap);
	return r;
}

int printf_256colored(color256_t fr_color, color256_t bk_color, char const * format, ...) {
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf_256colored(fr_color, bk_color, stdout, format, ap);
	va_end(ap);
	return r;
}

