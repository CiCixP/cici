#include "geomShapeClass.h"

int main(int argc, const char * argv[]) {
  std::vector<double> par1 = {1, 2, 3, 4, 5};
  std::vector<double> par2 = {3, 5, 7, 9, 2};
  std::vector<double> par3 = {4, 6, 6, 7, 5};
  std::vector<geometricShape *> shapeObj;
  
  for (int i = 0; i < par1.size(); i++)
  {
    shapeObj.push_back(new Rectangle (2,4));
  }
  return 0;
}
