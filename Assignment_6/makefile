EXECUTABLE_NAME = main
SRC=src
GENERATED=$(SRC)/generated

CC=g++
CCARGS= -c -I /usr/local/include/antlr4-runtime/ -I $(GENERATED)/src/ -I src/intermediate/.. -I src/..
LDARGS= -g
LIBS= /usr/local/lib/libantlr4-runtime.a

OUTPUT=objectFiles

antlrgencpp = $(wildcard $(GENERATED)/src/*.cpp)
antlrgenobj = $(addprefix $(OUTPUT)/,$(notdir $(antlrgencpp:.cpp=.o)))

intermediateCpp = $(wildcard src/intermediate/*/*.cpp)
intermediateObjects = $(addprefix $(OUTPUT)/,$(notdir $(intermediateCpp:.cpp=.o)))

srcCpp = $(wildcard src/*.cpp)
srcObjects = $(addprefix $(OUTPUT)/,$(notdir $(srcCpp:.cpp=.o)))

.PHONY: build antlr4 clean purge

build: $(antlrgenobj) $(intermediateObjects) $(srcObjects)
	$(CC) $(LDARGS) $(antlrgenobj) $(intermediateObjects) $(srcObjects) $(LIBS) -o $(EXECUTABLE_NAME)

antlr4: $(SRC)/Pascal.g4
	mkdir -p $(GENERATED) 
	java -jar antlr-4.7.2-complete.jar -visitor -no-listener -Dlanguage=Cpp $(SRC)/Pascal.g4 -o $(GENERATED)

clean:
	rm -rf $(OUTPUT)
	rm -f main


purge: clean
	rm -rf $(GENERATED)

$(OUTPUT)/%.o: $(GENERATED)/src/%.cpp
	mkdir -p $(OUTPUT) 
	$(CC) $(CCARGS)  $< -o $@

$(OUTPUT)/%.o: src/intermediate/*/%.cpp
	mkdir -p $(OUTPUT)
	$(CC) $(CCARGS)  $< -o $@

$(OUTPUT)/%.o: src/%.cpp
	mkdir -p $(OUTPUT)
	$(CC) $(CCARGS)  $< -o $@