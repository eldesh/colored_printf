
CC= gcc
CFLAGS= -Wall -Wextra -I../include

VPATH= .:..:../src:../src/detail

TARGET= colorspace-sample

SRC= colorspace-sample.c
OBJ= $(SRC:.c=.o)
COLOR_PRINTF_SRC= raw_256colored_printf.c raw_colored_printf.c raw_gray_printf.c
COLOR_PRINTF_OBJ= $(COLOR_PRINTF_SRC:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.d: %.c
	@echo "generate [$@] from [$*]"
	@$(SHELL) -ec '$(CC) -MM $(CFLAGS) $< \
		| sed "s/\($*\)\.o[ :]*/\1.o $@ : /g" > $@; \
		[ -s $@ ] || rm -rf $@'

$(TARGET): $(COLOR_PRINTF_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(COLOR_PRINTF_OBJ) $(OBJ)

ifeq (,$(findstring $(MAKECMDGOALS),clean))
include $(SRC:.c=.d)
include $(COLOR_PRINTF_SRC:.c=.d)
endif

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ)
	rm -rf $(COLOR_PRINTF_OBJ)
	rm -rf $(COLOR_PRINTF_SRC:.c=.d)

