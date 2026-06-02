CXX      := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g -Iinclude
BUILD    := build

# Each subdirectory of exercises/ that has a main.cpp becomes a target.
EXERCISES := $(notdir $(patsubst %/main.cpp,%,$(wildcard exercises/*/main.cpp)))
BINS      := $(addprefix $(BUILD)/,$(EXERCISES))

.PHONY: all clean list
all: $(BINS) compile_commands.json

# Build rule: compile every .cpp under exercises/<name>/ into build/<name>
# -MJ also emits a compilation-database fragment for clangd (editor linting).
$(BUILD)/%: exercises/%/*.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -Iexercises/$* -MJ $(BUILD)/$*.cc.json $^ -o $@

# Merge the per-exercise fragments so the editor knows how each file is compiled.
compile_commands.json: $(BINS)
	@sed -e '1s/^/[\n/' -e '$$s/,$$/\n]/' $(BUILD)/*.cc.json > $@

$(BUILD):
	@mkdir -p $(BUILD)

# `make run-ex01_hello` builds and runs that exercise
run-%: $(BUILD)/%
	@./$<

list:
	@echo $(EXERCISES) | tr ' ' '\n'

clean:
	rm -rf $(BUILD) compile_commands.json
