EXECUTABLE_NAME = main
MAIN_FILE = src/ExprMain.cpp

OUTPUT=output
GENERATED=generated

antlrgencpp = $(wildcard $(GENERATED)/src/*.cpp)
antlrgenobj = $(addprefix $(OUTPUT)/,$(notdir $(antlrgencpp:.cpp=.o)))

intermediateCpp = $(wildcard intermediate/*/*.cpp)
intermediateObjects = $(addprefix $(OUTPUT)/intermediate/,$(notdir $(intermediateCpp:.cpp=.o)))

frontendCpp = $(wildcard frontend/*.cpp)
frontendObjects = $(addprefix $(OUTPUT)/frontend/,$(notdir $(frontendCpp:.cpp=.o)))

# here is where you plug in the runtime for your OS
CC=g++
CCARGS= -c -I /usr/local/include/antlr4-runtime/ -I $(GENERATED)/src/ -I intermediate/.. -I frontend/..
LDARGS= -g
LIBS= /usr/local/lib/libantlr4-runtime.a
SRC=src

.PHONY: build antlr4 clean purge fresh

build: $(MAIN_FILE) $(antlrgenobj) $(intermediateObjects) $(frontendObjects)
	mkdir -p $(OUTPUT)/intermediate
	$(CC) $(CCARGS) $(MAIN_FILE) -o $(addprefix $(OUTPUT)/,$(notdir $(MAIN_FILE:.cpp=.o)))
	$(CC) $(LDARGS) $(addprefix $(OUTPUT)/,$(notdir $(MAIN_FILE:.cpp=.o))) $(antlrgenobj) $(intermediateObjects) $(frontendObjects) $(LIBS) -o $(EXECUTABLE_NAME)

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

$(OUTPUT)/intermediate/%.o: intermediate/*/%.cpp
	mkdir -p $(OUTPUT)/intermediate
	$(CC) $(CCARGS)  $< -o $@

$(OUTPUT)/frontend/%.o: frontend/%.cpp
	mkdir -p $(OUTPUT)/frontend
	$(CC) $(CCARGS)  $< -o $@