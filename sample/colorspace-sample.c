/**
 * sample & test of terminal's color capability
 *
 * output is similar to color-space.pl of the XTerm
 *
 * xterm: http://invisible-island.net/xterm/
 */
#include <stdio.h>
#include <stdlib.h>
#include "colored_printf.h"

void fprintf_system_colors (FILE * fp) {
	int i;
	fprintf(fp, "System colors:\n");

	fset_sgr_param(fp, TEXT_ATTR_OFF);
	for (i=0; i<8; ++i)
		fprintf_256colored(color256_of_gray(23), i, fp, "::");

	fprintf(fp, "\n");
	for (i=8; i<16; ++i)
		fprintf_256colored(color256_of_gray(23), i, fp, "::");

	fset_sgr_param(fp, TEXT_ATTR_OFF);
	fprintf(fp, "\n\n");
}

void fprintf_color_cube256 (FILE * fp) {
	uint8_t r,g,b;
	fprintf(fp, "Color cube, 6x6x6:\n");

	for (g=0; g<6; ++g) {
		for (r=0; r<6; ++r) {
			for (b=0; b<6; ++b) {
				fprintf_256colored(255, color256_of_rgb(r,g,b), fp, "::");
			}
			fset_sgr_param(fp, TEXT_ATTR_OFF);
			fprintf(fp, " ");
		}
		fprintf(fp, "\n");
	}
	fset_sgr_param(fp, TEXT_ATTR_OFF);
	fprintf(fp, "\n");
}

void fprintf_grayscale_ramp(FILE * fp) {
	uint8_t gray;
	fprintf(fp, "Grayscale ramp:\n");
	for (gray=0; gray<24; ++gray)
		fprintf_gray(23, gray, fp, "::");

	fset_sgr_param(fp, TEXT_ATTR_OFF);
	fprintf(fp, "\n\n");
}

void fprintf_16color (FILE * fp) {
	fprintf(fp, "Standard colors:\n");

	fprintf_colored(TERMINAL_FR_BLACK  , fp, "[%20s]", "TERMINAL_FR_BLACK  "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_RED    , fp, "[%20s]", "TERMINAL_FR_RED    "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_GREEN  , fp, "[%20s]", "TERMINAL_FR_GREEN  "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_YELLOW , fp, "[%20s]", "TERMINAL_FR_YELLOW "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_BLUE   , fp, "[%20s]", "TERMINAL_FR_BLUE   "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_MAGENTA, fp, "[%20s]", "TERMINAL_FR_MAGENTA"); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_CYAN   , fp, "[%20s]", "TERMINAL_FR_CYAN   "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_WHITE  , fp, "[%20s]", "TERMINAL_FR_WHITE  "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_FR_DEFAULT, fp, "[%20s]", "TERMINAL_FR_DEFAULT"); fprintf(fp, "\n");
	fprintf(fp, "\n");
	
	fprintf_colored(TERMINAL_BK_BLACK  , fp, "[%20s]", "TERMINAL_BK_BLACK  "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_RED    , fp, "[%20s]", "TERMINAL_BK_RED    "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_GREEN  , fp, "[%20s]", "TERMINAL_BK_GREEN  "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_YELLOW , fp, "[%20s]", "TERMINAL_BK_YELLOW "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_BLUE   , fp, "[%20s]", "TERMINAL_BK_BLUE   "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_MAGENTA, fp, "[%20s]", "TERMINAL_BK_MAGENTA"); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_CYAN   , fp, "[%20s]", "TERMINAL_BK_CYAN   "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_WHITE  , fp, "[%20s]", "TERMINAL_BK_WHITE  "); fprintf(fp, "\n");
	fprintf_colored(TERMINAL_BK_DEFAULT, fp, "[%20s]", "TERMINAL_BK_DEFAULT"); fprintf(fp, "\n");
	fprintf(fp, "\n");
}

int main (void) {
	fprintf_system_colors (stdout);
	fprintf_color_cube256 (stdout);
	fprintf_grayscale_ramp(stdout);
	fprintf_16color (stdout);
	return 0;
}


