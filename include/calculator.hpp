#pragma once

#include <string>
#include <vector>

class Calculator {
  enum class Operator {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULUS,
  };

  enum class TokenType {
    OPERATOR,
    OPERAND,
  };

  struct Token {
    TokenType type;
    union {
      Operator op;
      int operand;
    };
  };

 public:
  int calculate(const std::string &expression);

 private:
  std::vector<Token> parse_infix_expression(const std::string &expression);
  std::vector<Token> convert_to_postfix(const std::vector<Token> &infix);
  int precedence(Operator op);
  int evaluate_postfix(const std::vector<Token> &postfix);
};
