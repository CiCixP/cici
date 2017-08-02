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
    double * newArr = new double [index+1];
    for (int j = 0; j < _length; j++)
      newArr[j] = _Arr[j];
    for (int j = _length; j < index+1; j++)
      newArr[j] = 0;
    delete [] _Arr;
    _Arr = newArr;
    _length = index + 1;
  }
  return _Arr[index];
}

void dynDoub::add(int index, double x)
{
  if (index < _length)
    _Arr[index] = x;
  else
  {
    double * newArr = new double [index+1];
    for (int j = 0; j < _length; j++)
      newArr[j] = _Arr[j];
    for (int j = _length; j < index; j++)
      newArr[j] = 0;
    newArr[index] = x;
    _length = index + 1;
    delete [] _Arr;
    _Arr = newArr;
  }
}

int dynDoub::size()
{
  return _length;
}
