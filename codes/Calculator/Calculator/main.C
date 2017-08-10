#include "Calculator.h"
#include "CalcFunc.h"

int main(int argc, const char *argv[]) {
  const char exprToParse [] = "1.5^2 + 2*3 + 4";

  CalcFunc c(exprToParse);

  double result = c.eval();

  for (int i = 0; i < strlen(exprToParse); i++)
  {
    printf("%c", exprToParse[i]);
  }
  printf(" = %f \n", result);

  return 0;
}
