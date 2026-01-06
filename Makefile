# Detect OS
ifeq ($(OS),Windows_NT)
    # Windows
    RUN_CMD = .\$(EXEC)
else
    # Linux / macOS
    RUN_CMD = ./$(EXEC)
endif


# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -O3 -Wall -Iheaders -Iinclude

# Files
SRC = ray_tracer.cpp
OBJ = ray_tracer.o
EXEC = ray_tracer

# Auto-detect all headers in the headers/ folder
HEADERS = $(wildcard headers/*.h)

# Default target
all: $(EXEC)

# Build executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Compile object file
$(OBJ): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRC)

# Run the program
run: $(EXEC)
	$(RUN_CMD) > image.ppm

# Clean up
clean:
	rm -f $(OBJ) $(EXEC)
