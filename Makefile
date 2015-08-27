
CC ?= gcc
CFLAGS := -Wall -Wextra -Iinclude

VPATH= src:src/detail

LIB_DIR= lib
TARGET= $(LIB_DIR)/libcolored-printf.a

SRC= \
	raw_256colored_printf.c \
	raw_colored_printf.c \
	raw_gray_printf.c

OBJ := $(SRC:.c=.o)

all: $(TARGET)

%.o: %.c
	@echo "  CC [$@]"
	@$(CC) $(CFLAGS) -c $<

%.d: %.c
	@echo "  GEN [$@]"
	@$(SHELL) -ec '$(CC) -MM $(CFLAGS) $< \
		| sed "s/\($*\)\.o[ :]*/\1.o $@ : /g" > $@; \
		[ -s $@ ] || rm -rf $@'

$(TARGET): lib_dir_mk $(OBJ)
	@echo "  AR [$@]"
	@ar r $(TARGET) $(OBJ)

ifeq (,$(findstring $(MAKECMDGOALS),clean))
include $(SRC:.c=.d)
endif

.PHONY: sample
sample:
	@make -C sample

.PHONY: lib_dir_mk
lib_dir_mk:
	@echo "mkdir $(LIB_DIR)"
	@mkdir -p $(LIB_DIR)

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ)
	rm -rf $(SRC:.c=.d)
	@make -C sample clean

