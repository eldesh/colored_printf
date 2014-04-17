#include <stdio.h>
#include "detail/raw_colored_printf.h"
#include "detail/raw_256colored_printf.h"
#include "detail/raw_gray_printf.h"

void printf_system_colors (FILE * fp) {
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

void printf_color_cube216 (FILE * fp) {
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

int main (void) {
	printf_system_colors (stdout);
	printf_color_cube216 (stdout);
	return 0;
}

