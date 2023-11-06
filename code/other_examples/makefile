CC := g++
CFLAGS := -std=c++17 -Wall -Wextra -lgmpxx -lgmp
SRC_DIR := .
# Finds all subdirectories in the base directory
SUB_DIRS := $(shell find $(SRC_DIR) -type d)
# Finds all files ending with '.cpp'
SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_DIR := src
# Substitutes '.cpp' with '.o' from 'SRC_FILES'
# https://www.gnu.org/software/make/manual/make.html#Text-Functions
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean

# make
all: $(SUB_DIRS) $(OBJ_FILES)

$(SUB_DIRS):
	@mkdir -p $(OBJ_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# make clean
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\nCleaned.\n"