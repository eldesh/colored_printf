#include <stdio.h>
#include <assert.h>
#include "detail/raw_colored_printf.h"
#include "detail/raw_256colored_printf.h"

static uint8_t const TERMINAL_FR_256COLOR_TEXT = 38;
static uint8_t const TERMINAL_BK_256COLOR_TEXT = 48;

uint8_t color256_red  (color256_t color) {
	assert(16 <= color && color <= 16+216);
	return (color - 16) / 36;
}

uint8_t color256_green(color256_t color) {
	assert(16 <= color && color <= 16+216);
	return (color - 16) / 6;
}

uint8_t color256_blue (color256_t color) {
	assert(16 <= color && color <= 16+216);
	return (color - 16) / 1;
}

color256_t color256_of_std (uint8_t color) {
	assert(color < 16);
	return color;
}

color256_t color256_of_gray(uint8_t gray) {
	assert(gray < 24);
	return 232 + gray;
}

color256_t color256_of_rgb (uint8_t r, uint8_t g, uint8_t b) {
	assert(r < 6);
	assert(g < 6);
	assert(b < 6);
	return 16 + r*36 + g*6 + b;
}

int set_256color_foreground(FILE * fp, color256_t color) {
	return fprintf(fp, "\x1b[%d;5;%dm", TERMINAL_FR_256COLOR_TEXT, color);
}

int set_256color_background(FILE * fp, color256_t color) {
	return fprintf(fp, "\x1b[%d;5;%dm", TERMINAL_BK_256COLOR_TEXT, color);
}

int vfprintf_256colored(color256_t fr_color, color256_t bk_color, FILE * fp, char const * format, va_list ap) {
	int r;
	set_256color_foreground(fp, fr_color);
	set_256color_background(fp, bk_color);
	r = vfprintf(fp, format, ap);
	fset_sgr_param(fp, TEXT_ATTR_OFF);
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

