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
  void set(int index, Type x);
  Type * reallocate(int index);
  int size();
protected:
  Type * _Arr;
  int _length;
};

template <class Type>
dynArr<Type>::dynArr()
{
  _length = 2;
  _Arr = new Type [_length];
  for (int i = 0; i < _length; i++)
    _Arr[i] = 0;
}

template <class Type>
dynArr<Type>::~dynArr()
{
  delete [] _Arr;
}

template <class Type>
Type & dynArr<Type>::operator[](int index)
{
  if (index >= _length)
  {
    Type * newArr = reallocate(index);
    _Arr = newArr;
  }
  return _Arr[index];
}

template <class Type>
void dynArr<Type>::set(int index, Type x)
{
  if (index < _length)
    _Arr[index] = x;
  else
  {
    Type * newArr = reallocate(index);
    newArr[index] = x;
    _Arr = newArr;
  }
}

template <class Type>
Type * dynArr<Type>::reallocate(int index)
{
  Type * newArr = new Type [index+1];
  for (int j = 0; j < _length; j++)
    newArr[j] = _Arr[j];
  for (int j = _length; j < index+1; j++)
    newArr[j] = 0;
  _length = index + 1;
  delete [] _Arr;
  return newArr;
}

template <class Type>
int dynArr<Type>::size()
{
  return _length;
}

#endif /* DynamicArray_h */
