#include <stdio.h>
#include "detail/raw_colored_printf.h"
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

int main () {
	printf_system_colors (stdout);
	return 0;
}

