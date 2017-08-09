#include "CalcFunc.h"

CalcFunc::CalcFunc(const char expressionToParse[]) : expr(expressionToParse) {}

CalcFunc::~CalcFunc() {}

char CalcFunc::get() { return *expr++; }

char CalcFunc::peek() {
  if (*expr == ' ') {
    get();
  }
  return *expr;
}

int CalcFunc::number() {
  int result = get() - '0';
  while (peek() >= '0' && peek() <= '9') {
    result = 10 * result + get() - '0';
  }
  return result;
}

int CalcFunc::expression() {
  int result = term();
  if (peek() == ' ') {
    get();
  }
  while (peek() == '+' || peek() == '-')
    if (get() == '+')
      result += term();
    else
      result -= term();
  return result;
}

int CalcFunc::term() {
  int result = factor();
  while (peek() == '*' || peek() == '/')
    if (get() == '*')
      result *= factor();
    else {
      if (factor() == 0) {
        printf("Expression is undefined");
        exit(1);
      }
      result /= factor();
    }
  return result;
}

int CalcFunc::factor() {
  if (peek() >= '0' && peek() <= '9')
    return number();
  else if (peek() == '(') {
    get(); // '('
    int result = expression();
    get(); // ')'
    return result;
  } else if (peek() == '-') {
    get();
    return -factor();
  }

  return 0; // error
}
