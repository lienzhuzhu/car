# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -MMD -MP
CPPFLAGS = -Iinclude
LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -lraylib

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_FILE = sim

# Source, object, and dependency files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d)

# Output executable
EXECUTABLE = $(BUILD_DIR)/$(BIN_FILE)

# Default target
all: $(BUILD_DIR) $(EXECUTABLE)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Linking the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compiling source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Include the dependency files
-include $(DEPS)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(DEPS)

.PHONY: all clean
