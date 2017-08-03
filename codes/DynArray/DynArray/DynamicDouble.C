#include "DynamicDouble.h"

dynDoub::dynDoub()
{
  _length = 2;
  _Arr = new double [_length];
  for (int i = 0; i < _length; i++)
    _Arr[i] = 0;
}

dynDoub::~dynDoub()
{
  delete [] _Arr;
}

double & dynDoub::operator[](int index)
{
  if (index >= _length)
  {
    double * newArr = reallocate(index);
    _Arr = newArr;
  }
  return _Arr[index];
}

void dynDoub::set(int index, double x)
{
  if (index < _length)
    _Arr[index] = x;
  else
  {
    double * newArr = reallocate(index);
    newArr[index] = x;
    _Arr = newArr;
  }
}

double * dynDoub::reallocate(int index)
{
  double * newArr = new double [index+1];
  for (int j = 0; j < _length; j++)
    newArr[j] = _Arr[j];
  for (int j = _length; j < index+1; j++)
    newArr[j] = 0;
  _length = index + 1;
  delete [] _Arr;
  return newArr;
}

int dynDoub::size()
{
  return _length;
}
