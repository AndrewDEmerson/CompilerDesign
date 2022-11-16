#pragma once
#include "antlr4-runtime.h"

static const std::string ErrorDescription[] = {
    "INVALID_FIELD",
    "INVALID_CONSTANT",
    "INVALID_SIGN",
    "INVALID_TYPE",
    "INVALID_VARIABLE",
    "INVALID_CONTROL_VARIABLE",
    "INVALID_REFERENCE_PARAMETER",
    "INVALID_RETURN_TYPE",
    "INVALID_SUBSCRIPTS",
    "INVALID_ASSIGNMENT",
    "INVALID_COMPARISON",
    "MISMATCHED_TYPE",
    "EXPECTED_TYPE_INTEGER",
    "EXPECTED_TYPE_NUMERIC",
    "EXPECTED_TYPE_BOOLEAN",
    "DUPLICATE_CASE_CONSTANT",
    "NAME_MUST_BE_PROCEDURE",
    "NAME_MUST_BE_FUNCTION",
    "UNEQUAL_ARGUMENT_COUNTS",
    "ARGUMENT_MUST_BE_VARIABLE",
    "UNDECLARED_IDENTIFIER",
    "REDECLARED_IDENTIFIER",
};

class ErrorHandler {
public:
  enum class Error {
    INVALID_FIELD,
    INVALID_CONSTANT,
    INVALID_SIGN,
    INVALID_TYPE,
    INVALID_VARIABLE,
    INVALID_CONTROL_VARIABLE,
    INVALID_REFERENCE_PARAMETER,
    INVALID_RETURN_TYPE,
    INVALID_SUBSCRIPTS,
    INVALID_ASSIGNMENT,
    INVALID_COMPARISON,
    MISMATCHED_TYPE,
    EXPECTED_TYPE_INTEGER,
    EXPECTED_TYPE_NUMERIC,
    EXPECTED_TYPE_BOOLEAN,
    DUPLICATE_CASE_CONSTANT,
    NAME_MUST_BE_PROCEDURE,
    NAME_MUST_BE_FUNCTION,
    UNEQUAL_ARGUMENT_COUNTS,
    ARGUMENT_MUST_BE_VARIABLE,
    UNDECLARED_IDENTIFIER,
    REDECLARED_IDENTIFIER,
  };
  void log(Error error, int lineNumber, std::string text) {
    printf("%s @ LineNumber %d, Context is: %s\n", ErrorDescription[int(error)].c_str(), lineNumber, text.c_str());
  }
  void log(Error error, antlr4::ParserRuleContext *ctx) {
    log(error, ctx->getStart()->getLine(), ctx->getText());
  }
};
