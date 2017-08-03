//#include "DynamicArray.h"
//
//template <class Type>
//dynArr<Type>::dynArr()
//{
//  _length = 2;
//  _Arr = new Type [_length];
//  for (int i = 0; i < _length; i++)
//    _Arr[i] = 0;
//}
//
//template <class Type>
//dynArr<Type>::~dynArr()
//{
//  delete [] _Arr;
//}
//
//template <class Type>
//Type & dynArr<Type>::operator[](int index)
//{
//  if (index >= _length)
//  {
//    Type * newArr = new Type [index+1];
//    for (int j = 0; j < _length; j++)
//      newArr[j] = _Arr[j];
//    for (int j = _length; j < index+1; j++)
//      newArr[j] = 0;
//    delete [] _Arr;
//    _Arr = newArr;
//    _length = index + 1;
//  }
//return _Arr[index];
//}
//
//template <class Type>
//void dynArr<Type>::add(int index, Type x)
//{
//  if (index < _length)
//    _Arr[index] = x;
//  else
//  {
//    Type * newArr = new Type [index+1];
//    for (int j = 0; j < _length; j++)
//      newArr[j] = _Arr[j];
//    for (int j = _length; j < index; j++)
//      newArr[j] = 0;
//    newArr[index] = x;
//    _length = index + 1;
//    delete [] _Arr;
//    _Arr = newArr;
//  }
//}
//
//template <class Type>
//int dynArr<Type>::size()
//{
//  return _length;
//}
