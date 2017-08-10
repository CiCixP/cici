#ifndef CalcFunc_h
#define CalcFunc_h

#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

class CalcFunc {
public:
  CalcFunc(const char expressionToParse[]);
  ~CalcFunc();
  double eval();

protected:
  const char *expr;
  double AddSub();
  double MultDiv();
  double Expo();
  double NumPar();
  double number();
  char peek();
  char get();
};

#endif /*CalcFunc_h*/
