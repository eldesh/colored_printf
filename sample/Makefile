
CC ?= gcc
CFLAGS := -std=c99 -g -Wall -Wextra -I../include -L../lib

TARGETS := colorchart show_ppm

SRC := $(TARGETS:=.c)
OBJ := $(SRC:.c=.o)
LIB := colored-printf

all: $(TARGETS)

%.o: %.c
	@echo "  CC [$@]"
	@$(CC) $(CFLAGS) -c $<

%.d: %.c
	@echo "  GEN [$@]"
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
	$(RM) -r $(TARGETS)
	$(RM) -r $(OBJ)
	$(RM) -r $(SRC:.c=.d)

