#include "Calculator.h"

calculate::calculate(std::string input)
{
  
}
calculate::~calculate() {}

double calculate::expression()
{
  // term or sum/difference of terms
  double result = term();
  bool more = true;
  while (more)
  {
    char op = std::cin.peek();
    if (op == '+' || op == '-')
    {
      std::cin.get();
      int value = term();
      if (op == '+') result += value;
      else result -= value;
    }
    else more = false;
  }
  
  return result;
}

double calculate::factor()
{
  // a number
  double result = 0;
  char c = std::cin.peek();
  while (isdigit(c))
  {
    result = 10 * result + c - '0';
    std::cin.get();
    c = std::cin.peek();
  }
  return result;
}

double calculate::term()
{
  // a factor or product/quotient of factors
  double result = factor();
  bool more = true;
  while (more)
  {
    char op = std::cin.peek();
    if (op == '*' || op == '/')
    {
      std::cin.get();
      int value = term();
      if (op == '*') result *= value;
      else
      {
        if (value == 0)
        {
          printf("Expression is undefined");
          exit(1);
        }
        result = result / value;
      }
    }
    else more = false;
  }
  
  return result;
}
