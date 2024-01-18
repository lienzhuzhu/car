# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17
CPPFLAGS = -Iinclude
LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -lraylib

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_FILE = sim

# Source and object files
SOURCE_FILE = $(SRC_DIR)/main.cpp
OBJECT_FILE = $(BUILD_DIR)/main.o

# Output executable
EXECUTABLE = $(BUILD_DIR)/$(BIN_FILE)

# Default target
all: $(BUILD_DIR) $(EXECUTABLE)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Linking the executable
$(EXECUTABLE): $(OBJECT_FILE)
	$(CXX) $(OBJECT_FILE) -o $(EXECUTABLE) $(LDFLAGS)

# Compiling source files
$(OBJECT_FILE): $(SOURCE_FILE)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_FILE) -o $(OBJECT_FILE)

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
