#include "Calculator.h"

int main(int argc, const char *argv[]) {
  cout << "Enter equation/expression \n";
  cin;

  calculate c;

  cout << c.expression() << endl;

  return 0;
}
