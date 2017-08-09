#ifndef CalcFunc_h
#define CalcFunc_h

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

class CalcFunc {
public:
  CalcFunc(const char expressionToParse[]);
  ~CalcFunc();
  int expression();

protected:
  const char *expr;
  char get();
  char peek();
  int number();
  int term();
  int factor();
};

#endif /*CalcFunc_h*/
