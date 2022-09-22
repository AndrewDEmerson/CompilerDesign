EXECUTABLE_NAME = parser

# Files
OBJECTS += parser.o
OBJECTS += lexbuffer.o
OBJECTS += tokenizer.o
OBJECTS += tokenstream.o
OBJECTS += node.o
OBJECTS += symbolTable.o

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
	@mkdir -p ./bin/obj
	$(LINK) $(LINKFLAGS) $< -o $@

clean:
	rm -rf ./bin
	rm -f "out.txt"