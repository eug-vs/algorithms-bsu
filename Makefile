SOURCE_DIR=src
BUILD_DIR=build
CC=g++

ALL = $(basename $(addprefix $(BUILD_DIR)/, $(notdir $(wildcard src/*.cc))))

.PHONY: clean

all: $(ALL)

$(BUILD_DIR)/%: $(SOURCE_DIR)/%.cc | $(BUILD_DIR)
	$(CC) $< -o $@ -Wall

$(BUILD_DIR):
	@mkdir $@

clean:
	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);
	@echo Clean done.

