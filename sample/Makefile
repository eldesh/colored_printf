
CC ?= gcc
CFLAGS= -Wall -Wextra -I../include -L../lib

VPATH= .:..:../src:../src/detail

TARGET= colorspace-sample

SRC= colorspace-sample.c
OBJ= $(SRC:.c=.o)
LIB= colored-printf

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.d: %.c
	@echo "generate [$@] from [$*]"
	@$(SHELL) -ec '$(CC) -MM $(CFLAGS) $< \
		| sed "s/\($*\)\.o[ :]*/\1.o $@ : /g" > $@; \
		[ -s $@ ] || rm -rf $@'

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -l$(LIB)

ifeq (,$(findstring $(MAKECMDGOALS),clean))
include $(SRC:.c=.d)
endif

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ)
	rm -rf $(SRC:.c=.d)

