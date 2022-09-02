EXECUTABLE_NAME = scanner

# Files
OBJECTS += scanner.o
OBJECTS += lexbuffer.o
OBJECTS += tokenizer.o

# Directories
SRC = src
BIN = bin
OBJ = $(BIN)/obj

# Compiler options
CXX = g++
CXXFLAGS = -ggdb
LINK = g++
LINKFLAGS = -ggdb -c

OBJECT_FILES=$(addprefix $(OBJ)/, $(OBJECTS))

.PHONY: build clean

build: $(BIN)/$(EXECUTABLE_NAME)

$(BIN)/$(EXECUTABLE_NAME): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(LINK) $(LINKFLAGS) $< -o $@

clean:
	find $(BIN) -type f -exec rm {} +