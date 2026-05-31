CXX      := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g -Iinclude
BUILD    := build

# Each subdirectory of exercises/ that has a main.cpp becomes a target.
EXERCISES := $(notdir $(patsubst %/main.cpp,%,$(wildcard exercises/*/main.cpp)))
BINS      := $(addprefix $(BUILD)/,$(EXERCISES))

.PHONY: all clean list
all: $(BINS)

# Build rule: compile every .cpp under exercises/<name>/ into build/<name>
$(BUILD)/%: exercises/%/*.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -Iexercises/$* $^ -o $@

$(BUILD):
	@mkdir -p $(BUILD)

# `make run-ex01_hello` builds and runs that exercise
run-%: $(BUILD)/%
	@./$<

list:
	@echo $(EXERCISES) | tr ' ' '\n'

clean:
	rm -rf $(BUILD)
