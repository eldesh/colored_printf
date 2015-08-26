/**
 * a sample program show a ppm formatted image
 * to a terminal using libcolored-printf.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "colored_printf.h"

/**
 * \invariant width > 0
 * \invariant height > 0
 * \invariant maxval > 0
 */
typedef struct {
	size_t width;
	size_t height;
	uint16_t maxval;
	union {
		uint8_t  * byte1s;
		uint16_t * byte2s;
	} u;
} ppm_t;

size_t sizeof_ppm_t (ppm_t const * ppm) {
	assert(ppm);
	if (256 <= ppm->maxval)
		return 2 * 3 * ppm->width * ppm->height;
	else
		return     3 * ppm->width * ppm->height;
}

ppm_t * make_ppm_t (size_t width, size_t height, uint16_t maxval) {
	assert(0 < width);
	assert(0 < height);
	assert(0 < maxval);
	ppm_t * ppm = (ppm_t*)calloc(1, sizeof(ppm_t));
	if (!ppm) 
		return NULL;
	ppm->width  = width;
	ppm->height = height;
	ppm->maxval = maxval;
	if (256 <= maxval) {
		ppm->u.byte2s = (uint16_t*)calloc(2*3*width*height, sizeof(uint16_t));
		if (!ppm->u.byte2s) {
			free(ppm);
			return NULL;
		}
	} else {
		ppm->u.byte1s = (uint8_t*)calloc(3*width*height, sizeof(uint8_t));
		if (!ppm->u.byte1s) {
			free(ppm);
			return NULL;
		}
	}
	return ppm;
}

void delete_ppm_t (ppm_t * ppm) {
	if (ppm) {
		if (256 <= ppm->maxval) {
			free(ppm->u.byte2s);
			ppm->u.byte2s = NULL;
		} else {
			free(ppm->u.byte1s);
			ppm->u.byte1s = NULL;
		}
		ppm->width  = 0;
		ppm->height = 0;
		ppm->maxval = 0;
		free(ppm);
	}
}

/**
 * read ppm header
 *
 * parse width, height and maxval from fp
 */
static void read_ppm_header (FILE * fp, size_t * width, size_t * height, uint16_t * maxval) {
	char buff[256] = "";
	size_t const buff_len = sizeof(buff)/sizeof(buff[0]);

	if (NULL == fgets(buff, buff_len, fp)) {
		if (strncmp(buff, "P6\n", 3))
			goto ERROR;
	}
	if (NULL == fgets(buff, buff_len, fp))
		goto ERROR;

	size_t width_, height_;
	int r = sscanf(buff, "%zu %zu", &width_, &height_);
	if (r < 2 || r == EOF)
		goto ERROR;

	if (NULL == fgets(buff, buff_len, fp))
		goto ERROR;

	uint16_t maxval_;
	r = sscanf(buff, "%hd", &maxval_);
	if (r < 1 || r == EOF)
		goto ERROR;

	*width = width_;
	*height = height_;
	*maxval = maxval_;
ERROR:
	return;
}

void dump_ppm_header(FILE * fp, ppm_t const * ppm) {
	assert(fp);
	assert(ppm);

	printf("P6 %zu %zu %u", ppm->width, ppm->height, ppm->maxval);
}

ppm_t * ppm_from_file (FILE * fp) {
	assert(fp);

	size_t width, height;
	uint16_t maxval;
	read_ppm_header(fp, &width, &height, &maxval);

	ppm_t * ppm = make_ppm_t(width, height, maxval);
	if (!ppm)
		return NULL;
	ppm->width = width;
	ppm->height = height;
	ppm->maxval = maxval;

	if (256 <= ppm->maxval) {
		size_t const r = fread(ppm->u.byte2s, 2, 3*ppm->width*ppm->height, fp);
		if (r < sizeof_ppm_t(ppm))
			goto ERROR;
	} else {
		size_t const r = fread(ppm->u.byte1s, 1, 3*ppm->width*ppm->height, fp);
		if (r < sizeof_ppm_t(ppm))
			goto ERROR;
	}
	return ppm;
ERROR:
	delete_ppm_t(ppm);
	return NULL;
}

void ppm_sub1
			( ppm_t const * ppm, size_t h, size_t w
			, uint8_t * r
			, uint8_t * g
			, uint8_t * b )
{
	assert(ppm);
	assert(ppm->maxval < 256);
	assert(r && g && b);
	
	uint8_t const * p = &ppm->u.byte1s[h * 3*ppm->width + w*3];
	*r = p[0];
	*g = p[1];
	*b = p[2];
}

void dump_ppm_t (FILE * fp, ppm_t const * ppm) {
	assert(fp);
	assert(ppm);
	assert(ppm->maxval < 256);

	for (size_t h=0; h<ppm->height; ++h) {
		for (size_t w=0; w<ppm->width; ++w) {
			uint8_t r,g,b;
			ppm_sub1 (ppm, h, w, &r, &g, &b);
			fprintf_256colored(255, color256_of_rgb(r/43,g/43,b/43), fp, "  ");
		}
		fprintf(fp, "\n");
	}
}

static void usage(FILE * fp, char const * prog) {
	fprintf(fp, "%s <file.ppm>\n", prog);
	fprintf(fp, "\tfile.ppm : 8bit rgb format\n");
	exit(EXIT_SUCCESS);
}

int main (int argc, char * argv[]) {
	if (argc < 2)
		usage(stdout, argv[0]);

	fprintf(stdout, "load file %s...\n", argv[1]);
	FILE * ppm_file = fopen(argv[1], "rb");
	if (!ppm_file)
		exit(EXIT_SUCCESS);

	ppm_t * ppm = ppm_from_file(ppm_file);
	if (ppm) {
		dump_ppm_header(stdout, ppm); fprintf(stdout, "\n");
		dump_ppm_t(stdout, ppm);
	} else
		fprintf(stderr, "load ppm:%s failed\n", argv[1]);

	delete_ppm_t(ppm);
	fclose(ppm_file);
	return 0;
}

