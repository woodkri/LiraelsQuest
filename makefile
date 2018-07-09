# Author: Kristin Wood
# Project Name: 162 Final Project
# Date: 3/14/18
# Makefile based on example provided by TA Harlan James.

#
# Project Name
#
PROJ = FinalProject_Wood_Kristin

#
# Compiler
#
$(CXX) = g++

#
# Source Files
#
SRC  = main.cpp
SRC += AbhorsenHouse.cpp
SRC += Belisaere.cpp
SRC += ClayrGlacier.cpp
SRC += Death.cpp
SRC += Game.cpp
SRC += isInt.cpp
SRC += Lirael.cpp
SRC += NorthernBorder.cpp
SRC += Space.cpp
SRC += Wall.cpp

#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
BIN = $(PROJ).bin

#
# Compiler Flags
#
CFLAGS = -Wall -pedantic-errors -std=gnu++11

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

#
# Names of tags that aren't actually files.
#
.PHONY: default debug clean zip

#
# Default Behavior:
#     1. Remove everything to start from scratch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(BIN) debug

#
# Notice the dependency chain.
#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
# 
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

#
# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN)

