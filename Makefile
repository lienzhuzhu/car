# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -lraylib

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SOURCE_FILES = $(SRC_DIR)/main.cpp
OBJECT_FILES = $(BUILD_DIR)/main.o

# Output executable
EXECUTABLE = $(BUILD_DIR)/app

# Default target
all: $(EXECUTABLE)

# Linking the executable
$(EXECUTABLE): $(OBJECT_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECT_FILES) -o $(EXECUTABLE) $(LDFLAGS)

# Compiling source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
