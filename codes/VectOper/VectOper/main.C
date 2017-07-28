#include <iostream>
#include "vectorOperation.h"

int main(int argc, const char * argv[])
{
  std::vector<double> b = {1, 3, 5, 7, 9, 2, 4, 6, 8};
  vectorOperation vect(b);
  std::cout << vect(4) << std::endl;
  return 0;
}
