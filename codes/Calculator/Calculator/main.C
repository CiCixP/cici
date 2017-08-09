#include "Calculator.h"
#include "CalcFunc.h"

int main(int argc, const char *argv[]) {
  const char exprToParse [] = "3*2 + 4*1 + (4+9)*6";

  CalcFunc c(exprToParse);

  int result = c.expression();

  cout << result << endl;

  return 0;
}
