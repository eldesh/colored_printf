
CC ?= gcc
CFLAGS := -std=c99 -g -Wall -Wextra -I../include -L../lib

TARGETS := colorspace-sample show_ppm

SRC := colorspace-sample.c show_ppm.c
OBJ := $(SRC:.c=.o)
LIB := colored-printf

all: $(TARGETS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.d: %.c
	@echo "generate [$@] from [$*]"
	@$(SHELL) -ec '$(CC) -MM $(CFLAGS) $< \
		| sed "s/\($*\)\.o[ :]*/\1.o $@ : /g" > $@; \
		[ -s $@ ] || rm -rf $@'

$(TARGETS): %: %.o
	@echo "  LN [$@]"
	@$(CC) $(CFLAGS) -o $@ $^ -l$(LIB)

ifeq (,$(findstring $(MAKECMDGOALS),clean))
include $(SRC:.c=.d)
endif

.PHONY: clean
clean:
	rm -rf $(TARGETS)
	rm -rf $(OBJ)
	rm -rf $(SRC:.c=.d)

