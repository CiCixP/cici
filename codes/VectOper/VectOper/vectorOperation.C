#include "vectorOperation.h"

vectorOperation::vectorOperation(std::vector<double> v) : _vector(v) {}

double vectorOperation::operator[](int i)
{
  return _vector[i];
}

double vectorOperation::operator()(int i)
{
  return _vector[i];
}
