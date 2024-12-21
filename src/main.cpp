#include <iostream>
#include <string>

#include "calculator.hpp"

using namespace std;

int main() {
  string expr;
  cout << "----Welcome to expression calculator-----\n"
       << "Currently supported operations are : +, -, *, /, %\n"
       << "Enter the expression you want to calculate : ";
  getline(cin, expr);

  Calculator calc;
  try {
    int result = calc.calculate(expr);
    cout << expr << " = " << result << endl;
  } catch (const std::exception &e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
