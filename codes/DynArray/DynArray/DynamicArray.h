#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>
#include <iostream>

template <class Type>
class dynArr
{
public:
  dynArr();
  ~dynArr();
  Type & operator[](int index);
  void add(int index, Type x);
  int size();
protected:
  Type * _Arr;
  int _length;
};

#endif /* DynamicArray_h */
