#include "Calculator.h"
#include "CalcFunc.h"

int main(int argc, const char *argv[]) {
  const char exprToParse [] = "1.25 +2* 3";

  CalcFunc c(exprToParse);

  double result = c.eval();

  cout << result << endl;

  return 0;
}
