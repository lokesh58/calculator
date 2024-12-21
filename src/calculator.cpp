#include "calculator.hpp"

#include <sstream>
#include <stack>
#include <stdexcept>

int Calculator::calculate(const std::string &expression) {
  auto infix = parse_infix_expression(expression);
  auto postfix = convert_to_postfix(infix);
  return evaluate_postfix(postfix);
}

std::vector<Calculator::Token> Calculator::parse_infix_expression(
    const std::string &expression) {
  std::vector<Token> tokens;
  std::istringstream stream(expression);
  char ch;
  while (stream >> ch) {
    if (isdigit(ch)) {
      stream.putback(ch);
      int value;
      stream >> value;
      tokens.push_back(Token{TokenType::OPERAND, .operand = value});
    } else {
      Operator op;
      switch (ch) {
        case '+':
          op = Operator::ADD;
          break;
        case '-':
          op = Operator::SUBTRACT;
          break;
        case '*':
          op = Operator::MULTIPLY;
          break;
        case '/':
          op = Operator::DIVIDE;
          break;
        case '%':
          op = Operator::MODULUS;
          break;
        default:
          throw std::invalid_argument("Invalid operator");
      }
      tokens.push_back(Token{TokenType::OPERATOR, .op = op});
    }
  }
  return tokens;
}

std::vector<Calculator::Token> Calculator::convert_to_postfix(
    const std::vector<Token> &infix) {
  std::vector<Token> postfix;
  std::stack<Operator> operators;
  for (const auto &token : infix) {
    if (token.type == TokenType::OPERAND) {
      postfix.push_back(token);
    } else {
      while (!operators.empty() &&
             precedence(operators.top()) >= precedence(token.op)) {
        postfix.push_back(Token{TokenType::OPERATOR, .op = operators.top()});
        operators.pop();
      }
      operators.push(token.op);
    }
  }
  while (!operators.empty()) {
    postfix.push_back(Token{TokenType::OPERATOR, .op = operators.top()});
    operators.pop();
  }
  return postfix;
}

int Calculator::precedence(Operator op) {
  switch (op) {
    case Operator::ADD:
    case Operator::SUBTRACT:
      return 1;
    case Operator::MULTIPLY:
    case Operator::DIVIDE:
    case Operator::MODULUS:
      return 2;
    default:
      throw std::invalid_argument("Invalid operator");
  }
}

int Calculator::evaluate_postfix(const std::vector<Token> &postfix) {
  std::stack<int> operands;
  for (const auto &token : postfix) {
    if (token.type == TokenType::OPERAND) {
      operands.push(token.operand);
    } else {
      int right = operands.top();
      operands.pop();
      int left = operands.top();
      operands.pop();
      int result;
      switch (token.op) {
        case Operator::ADD:
          result = left + right;
          break;
        case Operator::SUBTRACT:
          result = left - right;
          break;
        case Operator::MULTIPLY:
          result = left * right;
          break;
        case Operator::DIVIDE:
          result = left / right;
          break;
        case Operator::MODULUS:
          result = left % right;
          break;
        default:
          throw std::invalid_argument("Invalid operator");
      }
      operands.push(result);
    }
  }
  return operands.top();
}
