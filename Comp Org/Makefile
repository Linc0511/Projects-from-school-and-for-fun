# Specify your input and output files
INPUT_FILE = input.txt
HEADER_FILE = functions.h
SOURCE_FILE = generate_functions_header.c
OUTPUT_FILE = generate_functions_header

# Define the targets for your demos
DEMO_TARGETS = demo1.c demo2.c

# Define the default target
all: $(DEMO_TARGETS)

# Rule to build the first demo
demo1: demo1.c $(HEADER_FILE)
	gcc -o demo1 demo1.c $(HEADER_FILE) -Wall

# Rule to build the second demo
demo2: demo2.c $(HEADER_FILE)
	gcc -o demo2 demo2.c $(HEADER_FILE) -Wall

# Rule to generate functions.h from input.txt
$(HEADER_FILE): $(INPUT_FILE) $(OUTPUT_FILE)
	./$(OUTPUT_FILE) < $(INPUT_FILE)

# Clean up generated files and executables
clean:
	rm -f $(DEMO_TARGETS) $(HEADER_FILE)

# Rule to build everything
build: all

# Rule to produce an appropriate .zip file
submit:
	zip -9qjX submission.zip $(INPUT_FILE) $(SOURCE_FILE) $(DEMO_TARGETS) Makefile

# Ensure that make clean and make submit are not treated as dependencies
.PHONY: clean build submit




