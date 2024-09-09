# Variables
CXX = g++
CXXFLAGS = -Wall -g 
LDFLAGS = 
SOURCES = main.cc
OBJECTS = $(SOURCES:.cc=.o)
DEPENDS = $(OBJECTS:.o=.d)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/app

# Default target
all: $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link the target
$(TARGET): $(BUILD_DIR) $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

# Compile source files into object files
$(BUILD_DIR)/%.o: %.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPENDS)

# Clean object files and the target
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(DEPENDS) $(OBJECTS)

# Phony targets
.PHONY: all clean
