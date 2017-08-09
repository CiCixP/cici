#include "Calculator.h"

calculate::calculate() {}
calculate::~calculate() {}

double calculate::expression() {
  cout << "expression \n";
  // term or sum/difference of terms
  double result = term();
  bool more = true;
  while (more) {
    char op = cin.peek();
    if (op == '+' || op == '-') {
      cin.get();
      int value = term();
      if (op == '+')
        result += value;
      else
        result -= value;
    } else
      more = false;
  }
  //  printf("expression: %f \n", result);
  return result;
}

double calculate::term() {
  cout << "term \n";
  // a factor or product/quotient of factors
  double result = factor();
  bool more = true;
  while (more) {
    char op = cin.peek();
    if (op == '*' || op == '/') {
      cin.get();
      int value = term();
      if (op == '*')
        result *= value;
      else {
        if (value == 0) {
          printf("Expression is undefined");
          exit(1);
        }
        result /= value;
      }
    } else
      more = false;
  }
  //  printf("term: %f \n", result);
  return result;
}

double calculate::factor() {
  cout << "factor \n";
  // a number
  double result = 0;
  char c = cin.peek();
  while (isdigit(c) || c == ' ' || c == '.') {
    if (isdigit(c)) {
      cout << "result " << result << endl;
      cout << "c " << c << endl;
      result = 10 * result + c - '0';
      cin.get();
      // } else if (c == '.') {
      //   cin.putback('.');
      //   cin >> result;
      //   printf("factor1: %f \n", result);
    } else
      cin.get();
    c = cin.peek();
    cout << "c " << c << endl;
  }
  //  printf("factor: %f \n", result);
  return result;
}
