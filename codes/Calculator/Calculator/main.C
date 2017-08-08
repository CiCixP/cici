#include "Calculator.h"

int main(int argc, const char * argv[])
{
  std::string eq;
  std::cin >> eq;
  calculate c(eq);
  std::cout << c.expression();
  return 0;
}
