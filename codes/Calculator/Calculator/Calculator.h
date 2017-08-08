#ifndef Calculator_h
#define Calculator_h

#include <iostream>
#include <stdio.h>
#include <string>

class calculate
{
public:
  calculate(std::string input);
  ~calculate();
  double expression();
  double factor();
  double term();
};

#endif /* Calculator_h */
