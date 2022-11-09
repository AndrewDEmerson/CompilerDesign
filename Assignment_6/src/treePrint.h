#pragma once

#include <string>
#include "antlr4-runtime.h"

// Based on tree->toStringTree(&parser)
std::string printTree(antlr4::tree::ParseTree *t, antlr4::Parser *recog);