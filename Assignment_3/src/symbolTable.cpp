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
  for (int i = 0; i < entries.size(); i++) {
    std::cout << entries[i] << std::endl;
  }
}