CC := g++
CFLAGS := -std=c++17 -Wall -Wextra -lgmpxx -lgmp
SRC_DIR := .
SUB_DIRS := $(shell find $(SUB_DIR) -type d)
SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_DIR := src
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