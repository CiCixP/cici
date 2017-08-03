#include "DynamicArray.h"
#include "DynamicDouble.h"

int main(int argc, const char * argv[])
{
  dynDoub vectDoub;
  vectDoub.set(0,3.2);
  vectDoub.set(1,4.3);
  vectDoub.set(2,5.4);
  
  for (int i =0; i < vectDoub.size(); i++)
    printf("%f \n", vectDoub[i]);
  
  dynArr<double> vectDouble;
  dynArr<int> vectInt;
  vectDouble.set(0, 3.2);
  vectDouble.set(1,4.3);
  vectDouble.set(2,5.4);
  
  return 0;
}
