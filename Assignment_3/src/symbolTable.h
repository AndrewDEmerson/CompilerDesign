#pragma once

#include <string>
#include <vector>

class symbolTable{
  public:
    void updateTable(std::string varName);
    void printTable();
  private:
    std::vector<std::string> entries;
};
