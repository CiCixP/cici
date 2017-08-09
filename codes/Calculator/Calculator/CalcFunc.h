#ifndef CalcFunc_h
#define CalcFunc_h

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

class CalcFunc {
public:
  CalcFunc(const char expressionToParse []);
  ~CalcFunc();
  int number();
  int expression();
  int factor();
  int term();

protected:
  const char *expr;
  char peek();
  char get();
};

#endif /*CalcFunc_h*/
