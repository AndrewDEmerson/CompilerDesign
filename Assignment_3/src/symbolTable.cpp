#include "symbolTable.h"
#include <iostream>

void symbolTable::updateTable(std::string varName) {
  for (int i = 0; i < entries.size(); i++) {
    if (entries[i] == varName) {
      return;
    }
  }
  entries.push_back(varName);
}

void symbolTable::printTable() {
  std::cout << "\nPrinting Symbol Table" << std::endl;
  for (int i = 0; i < entries.size(); i++) {
    std::cout << "|\t" << entries[i] << std::endl;
  }
}