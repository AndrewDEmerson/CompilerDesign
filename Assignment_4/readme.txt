To generate files based on an antlr grammar file:
  antlr4 -visitor -no-listener -Dlanguage=Cpp src/Expr.g4 -o antlr_gen

To build the program
  mkdir build
  cd build
  cmake ..
  make -j 8

To fix VSCODE editor problems when including antlr_lib files
  (assuming your using clangd https://open-vsx.org/vscode/item?itemName=llvm-vs-code-extensions.vscode-clangd)
  build program like normal but instead use: 
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
  copy compile_commands.json to Assignment_4 folder
