#include "CalcFunc.h"

CalcFunc::CalcFunc(const char expressionToParse[]) : expr(expressionToParse) {}

CalcFunc::~CalcFunc() {}

double CalcFunc::eval() { return expression(); }

char CalcFunc::get() {
  return *expr++;
}

char CalcFunc::peek() {
  if (*expr == ' ') {
    get();
  }
  return *expr;
}

double CalcFunc::number() {
  double result = get() - '0';
  double dec = 0;
  int p = peek();
  while ((p >= '0' && p <= '9') || p == '.') {
    if (p >= '0' && p <= '9') {
      result = 10 * result + get() - '0';
      p = peek();
    } else {
      int n = 1;
      get();
      p = peek();
      while (p >= '0' && p <= '9') {
        dec = dec + (p - '0') * pow(0.1, n);
        n++;
        get();
        p = peek();
      }
    }
  }
  return result + dec;
}

double CalcFunc::expression() {
  double result = term();
  int p = peek();
  while (p == '+' || p == '-')
    if (get() == '+') {
      p = peek();
      result += term();
    } else {
      p = peek();
      result -= term();
    }
  return result;
}

double CalcFunc::term() {
  double result = factor();
  int p = peek();
  while (p == '*' || p == '/')
    if (get() == '*') {
      p = peek();
      result *= factor();
    } else {
      p = peek();
      if (factor() == 0) {
        printf("Expression is undefined");
        exit(1);
      }
      result /= factor();
    }
  return result;
}

double CalcFunc::factor() {
  int p = peek();
  if (p >= '0' && p <= '9') {
    double num = number();
    return num;
  } else if (p == '(') {
    get(); // '('
    double result = expression();
    get(); // ')'
    return result;
  }
  return 0; // error
}
