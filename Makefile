#this file automatically cleans, makes executable, runs
#1. make

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++23
# Target executable name
TARGET = hw2
# Source files, list all cpp files here
SRCS = main.cpp event.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET) run
#if you wish to not clean before every run just remove clean in the line above

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files to .o files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to prevent conflicts with files
.PHONY: all clean
