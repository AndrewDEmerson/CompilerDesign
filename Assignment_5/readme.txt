To build the program
  run 'make build'
  file will be outputed in main directory.

Run The Program.
  File will be generated in build directory with name main.
  Run the program with no arguments (./main) to read in from CIN.
  Run the program with a filepath to read from the file. (./main input.txt)




Development Instructuctions:
  To generate files based on an antlr grammar file:
    make antlr4

  To fix VSCODE editor problems when including antlr_lib files
    (assuming your using clangd https://open-vsx.org/vscode/item?itemName=llvm-vs-code-extensions.vscode-clangd)
    apt install bear
    bear make
