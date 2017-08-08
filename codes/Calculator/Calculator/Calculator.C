#include "Calculator.h"

calculate::calculate() {}
calculate::~calculate() {}

float calculate::expression() {
  // term or sum/difference of terms
  float result = term();
  bool more = true;
  while (more) {
    char op = cin.peek();
    if (op == '+' || op == '-') {
      cin.get();
      int value = term();
      if (op == '+')
        result += value;
      else
        result -= value;
    } else
      more = false;
  }

  return result;
}

float calculate::term() {
  // a factor or product/quotient of factors
  float result = factor();
  bool more = true;
  while (more) {
    char op = cin.peek();
    if (op == '*' || op == '/') {
      cin.get();
      int value = term();
      if (op == '*')
        result *= value;
      else {
        if (value == 0) {
          printf("Expression is undefined");
          exit(1);
        }
        result /= value;
      }
    } else
      more = false;
  }

  return result;
}

float calculate::factor() {
  // a number
  float result = 0;
  char c = cin.peek();
  while (isdigit(c) || c == ' ') {
    if (isdigit(c)) {
      result = 10 * result + c - '0';
      cin.get();
    } else
      cin.get();
    c = cin.peek();
  }
  return result;
}
