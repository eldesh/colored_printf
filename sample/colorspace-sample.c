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

	fprintf_qualify(fp, TEXT_ATTR_OFF);
	for (i=0; i<8; ++i)
		fprintf_256colored(255, i, fp, "::");

	fprintf(fp, "\n");
	for (i=8; i<16; ++i)
		fprintf_256colored(255, i, fp, "::");

	fprintf_qualify(fp, TEXT_ATTR_OFF);
	fprintf(fp, "\n\n");
}

void fprintf_color_cube216 (FILE * fp) {
	uint8_t r,g,b;
	fprintf(fp, "Color cube, 6x6x6:\n");

	for (g=0; g<6; ++g) {
		for (r=0; r<6; ++r) {
			for (b=0; b<6; ++b) {
				fprintf_256colored(255, make_color216_t(r,g,b), fp, "::");
			}
			fprintf_qualify(fp, TEXT_ATTR_OFF);
			fprintf(fp, " ");
		}
		fprintf(fp, "\n");
	}
	fprintf_qualify(fp, TEXT_ATTR_OFF);
	fprintf(fp, "\n\n");
}

void fprintf_grayscale_ramp(FILE * fp) {
	uint8_t gray;
	fprintf(fp, "Grayscale ramp:\n");
	for (gray=0; gray<24; ++gray)
		fprintf_gray(fp, 23, gray, "::");

	fprintf_qualify(fp, TEXT_ATTR_OFF);
	fprintf(fp, "\n\n");
}

int main (void) {
	fprintf_system_colors (stdout);
	fprintf_color_cube216 (stdout);
	fprintf_grayscale_ramp(stdout);
	return 0;
}


