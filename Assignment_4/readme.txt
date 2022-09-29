To build the program
  mkdir build
  cd build
  cmake ..
  make -j 8

Run The Program.
  File will be generated in build directory with name main.
  Run the program with no arguments (./main) to read in from CIN.
  Run the program with a filepath to read from the file. (./main ../input.txt)


Development Instructuctions:
  To generate files based on an antlr grammar file:
    java -jar antlr-4.7.2-complete.jar -visitor -no-listener -Dlanguage=Cpp src/Expr.g4 -o antlr_gen

  To fix VSCODE editor problems when including antlr_lib files
    (assuming your using clangd https://open-vsx.org/vscode/item?itemName=llvm-vs-code-extensions.vscode-clangd)
    build program like normal but instead use: 
      cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
    copy compile_commands.json to Assignment_4 folder
