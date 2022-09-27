
// Generated from src/Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual std::any visitProg(ExprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }


};

