CC      := gcc
CFLAGS  := -Wall -Wextra -Wpedantic -std=c11 -Iinclude -g -Wno-newline-eof -Wno-empty-translation-unit
LDFLAGS :=

TARGET  := myc

SRC_DIR := src
OBJ_DIR := build

SOURCES := $(shell find $(SRC_DIR) -name '*.c')
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "  LINK    $@"
	@ $(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "  CC      $<"
	@ $(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	@echo "  CC      build/"
	@rm -rf $(OBJ_DIR)
	@echo "  CC      myc"
	@rm -rf $(TARGET)
