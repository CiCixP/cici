#ifndef Calculator_h
#define Calculator_h

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

class calculate {
public:
  calculate();
  ~calculate();
  float expression();
  float factor();
  float term();
};

#endif /* Calculator_h */
