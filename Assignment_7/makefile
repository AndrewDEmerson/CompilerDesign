EXECUTABLE_NAME = main
SRC=./src
GENERATED=$(SRC)/generated

CC=g++
CCARGS= -c -g -I /usr/local/include/antlr4-runtime/ -I $(GENERATED)/src/ -I $(SRC)/intermediate/.. -I $(SRC)/backend/.. -I $(SRC)/..
LDARGS= -g
LIBS= /usr/local/lib/libantlr4-runtime.a

OUTPUT=$(SRC)/../objectFiles

antlrgencpp = $(wildcard $(GENERATED)/src/*.cpp)
antlrgenobj = $(addprefix $(OUTPUT)/,$(notdir $(antlrgencpp:.cpp=.o)))

intermediateCpp = $(wildcard $(SRC)/intermediate/*/*.cpp)
intermediateObjects = $(addprefix $(OUTPUT)/,$(notdir $(intermediateCpp:.cpp=.o)))

backendCpp = $(wildcard $(SRC)/backend/*.cpp)
backendObjects = $(addprefix $(OUTPUT)/,$(notdir $(backendCpp:.cpp=.o)))

srcCpp = $(wildcard $(SRC)/*.cpp)
srcObjects = $(addprefix $(OUTPUT)/,$(notdir $(srcCpp:.cpp=.o)))

.PHONY: build antlr4 clean purge

build: $(antlrgenobj) $(intermediateObjects) $(backendObjects) $(srcObjects)
	$(CC) $(LDARGS) $(antlrgenobj) $(intermediateObjects) $(backendObjects) $(srcObjects) $(LIBS) -o $(EXECUTABLE_NAME)

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

$(OUTPUT)/%.o: $(SRC)/intermediate/*/%.cpp
	mkdir -p $(OUTPUT)
	$(CC) $(CCARGS)  $< -o $@

$(OUTPUT)/%.o: $(SRC)/backend/%.cpp
	mkdir -p $(OUTPUT)
	$(CC) $(CCARGS)  $< -o $@

$(OUTPUT)/%.o: $(SRC)/%.cpp
	mkdir -p $(OUTPUT)
	$(CC) $(CCARGS)  $< -o $@