#ifndef CalcFunc_h
#define CalcFunc_h

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

class CalcFunc {
public:
  CalcFunc(const char expressionToParse[]);
  ~CalcFunc();
  double eval();

protected:
  const char *expr;
  char get();
  char peek();
  double number();
  double expression();
  double term();
  double factor();
};

#endif /*CalcFunc_h*/
