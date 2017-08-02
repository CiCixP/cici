#include "DynamicArray.h"
#include "DynamicDouble.h"

int main(int argc, const char * argv[])
{
  dynDoub vectDoub;
  vectDoub.add(0,3.2);
  vectDoub.add(1,4.3);
  vectDoub.add(2,5.4);
  
  for (int i =0; i < vectDoub.size(); i++)
    printf("%f \n", vectDoub[i]);
  
  dynArr<double> vectDouble;
  dynArr<int> vectInt;
  vectDouble.add(0,3.2);
  vectDouble.add(1,4.3);
  vectDouble.add(2,5.4);
  
  return 0;
}
