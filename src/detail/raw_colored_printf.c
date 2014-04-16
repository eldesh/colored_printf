#include <stdio.h>
#include "detail/raw_colored_printf.h"

//! terminal foreground color
uint8_t const TERMINAL_FR_BLACK   = 30;
uint8_t const TERMINAL_FR_RED     = 31;
uint8_t const TERMINAL_FR_GREEN   = 32;
uint8_t const TERMINAL_FR_YELLOW  = 33;
uint8_t const TERMINAL_FR_BLUE    = 34;
uint8_t const TERMINAL_FR_MAGENTA = 35;
uint8_t const TERMINAL_FR_CYAN    = 36;
uint8_t const TERMINAL_FR_WHITE   = 37;
uint8_t const TERMINAL_FR_256COLOR_TEXT = 38;
uint8_t const TERMINAL_FR_DEFAULT = 39;

// terminal background color
uint8_t const TERMINAL_BK_BLACK   = 40;
uint8_t const TERMINAL_BK_RED     = 41;
uint8_t const TERMINAL_BK_GREEN   = 42;
uint8_t const TERMINAL_BK_YELLOW  = 43;
uint8_t const TERMINAL_BK_BLUE    = 44;
uint8_t const TERMINAL_BK_MAGENTA = 45;
uint8_t const TERMINAL_BK_CYAN    = 46;
uint8_t const TERMINAL_BK_WHITE   = 47;
uint8_t const TERMINAL_BK_256COLOR_TEXT = 48;
uint8_t const TERMINAL_BK_DEFAULT = 49;

// Text attributes
uint8_t const TEXT_ATTR_OFF        = 0;
uint8_t const TEXT_ATTR_BOLD       = 1;
uint8_t const TEXT_ATTR_UNDERSCORE = 4;
uint8_t const TEXT_ATTR_BLINK      = 5;
uint8_t const TEXT_ATTR_REVERSE    = 7;
uint8_t const TEXT_ATTR_CONCEALED  = 8;

int fprintf_qualify (FILE * fp, uint8_t qualify) {
	return fprintf(fp, "\x1b[%dm", qualify);
}

int printf_qualify (uint8_t qualify) {
	return fprintf_qualify(stdout, qualify);
}

int vfprintf_colored(uint8_t qualify, FILE * fp, char const * format, va_list ap) {
	int r;
	fprintf_qualify(fp, qualify);
	r = vfprintf(fp, format, ap);
	fprintf_qualify(fp, TEXT_ATTR_OFF);
	return r;
}

int fprintf_colored(uint8_t qualify, FILE * fp, char const * format, ...) {
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf_colored(qualify, fp, format, ap);
	va_end(ap);
	return r;
}

int printf_colored(uint8_t qualify, char const * format, ...) {
	int r;
	va_list ap;
	va_start(ap, format);
	r = vfprintf_colored(qualify, stdout, format, ap);
	va_end(ap);
	return r;
}

