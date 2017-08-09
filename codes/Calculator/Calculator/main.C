#include "Calculator.h"
#include "CalcFunc.h"

int main(int argc, const char *argv[]) {
  const char exprToParse [16] = "3*2+4*1+(4+9)*6";

  CalcFunc c(exprToParse);

  int result = c.expression();
  
  cout << result << endl;

  return 0;
  //
  // cout << "Enter Equation/Expression : \n";
  // cin;
  // calculate c;
  // cout << c.expression() << endl;
  // string expr = " 1 + 2 * 3";
  // string oper[10];
  // string term[20];
  // int operCount = 0;
  // int termCount = 0;
  //
  // for ( int i = 0; i < expr.size(); i++)
  // {
  //   if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
  //   {
  //     oper[operCount] = expr[i];
  //     operCount++; termCount++;
  //   }
  //   else if (isdigit(expr[i]))
  //   {
  //     term[termCount] += expr[i];
  //   }
  // }
  // cout << oper[operCount-1] << endl;
  // cout << term[termCount] << endl;
}
