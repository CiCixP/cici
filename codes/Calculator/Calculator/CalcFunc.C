#include "CalcFunc.h"

CalcFunc::CalcFunc(const char expressionToParse[]) : expr(expressionToParse) {}

CalcFunc::~CalcFunc() {}

double CalcFunc::eval() { return AddSub(); }

double CalcFunc::AddSub() {
  printf("{AddSub :\n");
  double result = MultDiv();
  while (peek() == '+' || peek() == '-') {
    if (get() == '+') {
      result += MultDiv();
    } else {
      result -= MultDiv();
    }
  }
  printf(" return = %f \n exit AddSub} \n", result);
  return result;
}

double CalcFunc::MultDiv() {
  printf(" {MultDiv : \n");
  double result = NumPar();
  while (peek() == '*' || peek() == '/')
    if (get() == '*') {
      result *= NumPar();
    } else {
      if (NumPar() == 0) {
        printf("Expression is undefined");
        exit(1);
      }
      result /= NumPar();
    }
  printf("  return = %f exit MultDiv} \n", result);
  return result;
}

double CalcFunc::NumPar() {
  printf("  {NumPar : \n");
  if (peek() >= '0' && peek() <= '9') {
    double num = number();
    printf("   return = %f exit NumPar} \n", num);
    return num;
  } else if (peek() == '(') {
    get(); // '('
    double result = AddSub();
    get(); // ')'
    printf("   return = %f exit NumPar} \n", result);
    return result;
  }         /*else if (get() == '^') {
            printf("   exponent \n");
            double base = p;
            get();
            double expo = peek();
            printf("   return : %f exit NumPar} \n", pow(base,expo));
            return pow(base, expo);
          }*/
  return 0; // error
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

char CalcFunc::get() {
  printf("     call get %c \n", *(expr + 1));
  return *expr++;
}
