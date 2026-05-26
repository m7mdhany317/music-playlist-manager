# Makefile for Music Playlist Manager
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = playlist
SOURCES = main.cpp Playlist.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Remove all generated files
distclean: clean
	rm -f *.o *.out

# Rebuild from scratch
rebuild: distclean all

.PHONY: all run clean distclean rebuild
