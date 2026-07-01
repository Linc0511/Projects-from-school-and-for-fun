# Define source files and targets
SOURCE_FILE := input.txt
OUTPUT_FILE := output.c
HEADER_FILE := functions.h
DEMO_FILE1 := demo1.c
DEMO_FILE2 := demo2.c
OBJECTS := $(DEMO_FILE1:.c=.o) $(DEMO_FILE2:.c=.o)
EXECUTABLES := demo1 demo2
ZIP_FILE := submission.zip

# Compiler and flags
CC := gcc
CFLAGS := -g -Wall -Werror -Wextra -Wno-unused-parameter

# Targets
.PHONY: all clean submit

all: $(EXECUTABLES)

$(DEMO_FILE1): $(HEADER_FILE) $(OUTPUT_FILE) $(DEMO_FILE1:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

$(DEMO_FILE2): $(HEADER_FILE) $(OUTPUT_FILE) $(DEMO_FILE2:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLES) $(OBJECTS) $(ZIP_FILE) $(OUTPUT_FILE) $(HEADER_FILE)

submit: $(OUTPUT_FILE) $(DEMO_FILE1) $(DEMO_FILE2) $(HEADER_FILE) Makefile
	zip -9 $(ZIP_FILE) $^

# Generate C code and header file from the input text file
$(OUTPUT_FILE) $(HEADER_FILE): $(SOURCE_FILE)
	./your_tool_name_here.sh $< $(OUTPUT_FILE) $(HEADER_FILE)

# Build demo applications
demo1: $(DEMO_FILE1)

demo2: $(DEMO_FILE2)


