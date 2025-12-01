# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Project files
SRC = main.cpp CSVParser.cpp Sorter.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = vgsales

# Default rule
all: $(TARGET)

# Link step
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile step for each .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(OBJ) $(TARGET)

# Convenience target for rebuilding everything
rebuild: clean all
