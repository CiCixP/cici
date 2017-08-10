#include "CalcFunc.h"

CalcFunc::CalcFunc(const char expressionToParse[]) : expr(expressionToParse) {}

CalcFunc::~CalcFunc() {}

double CalcFunc::eval() { return AddSub(); }

double CalcFunc::AddSub() {
  double result = MultDiv();
  while (peek() == '+' || peek() == '-') {
    if (get() == '+') {
      result += MultDiv();
    } else {
      result -= MultDiv();
    }
  }
  return result;
}

double CalcFunc::MultDiv() {
  double result = Expo();
  while (peek() == '*' || peek() == '/')
    if (get() == '*') {
      result *= Expo();
    } else {
      if (Expo() == 0) {
        printf("Expression is undefined");
        exit(1);
      }
      result /= Expo();
    }
  return result;
}

double CalcFunc::Expo() {
  double result = NumPar();
  if (peek() == '^') {
    double base = result;
    get();
    double exponent = NumPar();
    result = pow(base, exponent);
  }
  return result;
}

double CalcFunc::NumPar() {
  if (peek() >= '0' && peek() <= '9') {
    double num = number();
    return num;
  } else if (peek() == '(') {
    get(); // '('
    double result = AddSub();
    get(); // ')'
    return result;
  } else {
    printf("Invalid expression! \n");
    exit(10);
  }
}

double CalcFunc::number() {
  double result = get() - '0';
  double dec = 0;
  while ((peek() >= '0' && peek() <= '9') || peek() == '.') {
    if (peek() >= '0' && peek() <= '9') {
      result = 10 * result + get() - '0';
    } else {
      int n = 1;
      get();
      while (peek() >= '0' && peek() <= '9') {
        dec = dec + (peek() - '0') * pow(0.1, n);
        n++;
        get();
      }
    }
  }
  return result + dec;
}

char CalcFunc::peek() {
  if (*expr == ' ') {
    get();
  }
  return *expr;
}

char CalcFunc::get() { return *expr++; }
