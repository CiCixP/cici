#ifndef DynamicDouble_h
#define DynamicDouble_h

#include <stdio.h>
#include <iostream>

class dynDoub
{
public:
  dynDoub();
  ~dynDoub();
  double & operator[](int index);
  void add(int index, double x);
  int size();
protected:
  double * _Arr;
  int _length;
};

#endif /* DynamicDouble_h */
