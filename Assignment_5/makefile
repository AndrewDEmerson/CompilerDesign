EXECUTABLE_NAME = main
MAIN_FILE = src/ExprMain.cpp

OUTPUT=output
GENERATED=generated

antlrgencpp = $(wildcard $(GENERATED)/src/*.cpp)
antlrgenobj = $(addprefix $(OUTPUT)/,$(notdir $(antlrgencpp:.cpp=.o)))

# here is where you plug in the runtime for your OS
CC=g++
CCARGS= -c -I /usr/local/include/antlr4-runtime/ -I $(GENERATED)/src/
LDARGS= -g
LIBS= /usr/local/lib/libantlr4-runtime.a
SRC=src

.PHONY: build antlr4 clean purge fresh

build: $(MAIN_FILE) $(antlrgenobj)
	mkdir -p $(OUTPUT) 
	$(CC) $(CCARGS) $(MAIN_FILE) -o $(addprefix $(OUTPUT)/,$(notdir $(MAIN_FILE:.cpp=.o)))
	$(CC) $(LDARGS) $(addprefix $(OUTPUT)/,$(notdir $(MAIN_FILE:.cpp=.o))) $(antlrgenobj) $(LIBS) -o $(EXECUTABLE_NAME)

antlr4: $(SRC)/Expr.g4
	mkdir -p $(GENERATED) 
	java -jar antlr-4.7.2-complete.jar -visitor -no-listener -Dlanguage=Cpp $(SRC)/Expr.g4 -o $(GENERATED)

clean:
	rm -rf $(OUTPUT)

purge: clean
	rm -rf $(GENERATED)

$(OUTPUT)/%.o: $(GENERATED)/src/%.cpp
	mkdir -p $(OUTPUT) 
	$(CC) $(CCARGS)  $< -o $@
