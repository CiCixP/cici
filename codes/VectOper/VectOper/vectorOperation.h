#ifndef vectorOperation_h
#define vectorOperation_h

#include <stdio.h>
#include <vector>

class vectorOperation
{
public:
  vectorOperation(std::vector<double> v);
  double operator[](int i);
  double operator()(int i);
protected:
  std::vector<double> _vector;
};

#endif /* vectorOperation_h */
