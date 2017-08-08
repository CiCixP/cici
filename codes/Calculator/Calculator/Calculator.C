#include "Calculator.h"

calculate::calculate()
{
  
}
calculate::~calculate() {}

int calculate::expression()
{
  // term or sum/difference of terms
  int result = term();
  bool more = true;
  while (more)
  {
    char op = cin.peek();
    if (op == '+' || op == '-')
    {
      cin.get();
      int value = term();
      if (op == '+') result += value;
      else result -= value;
    }
    else more = false;
  }
  
  return result;
}

int calculate::term()
{
  // a factor or product/quotient of factors
  int result = factor();
  bool more = true;
  while (more)
  {
    char op = cin.peek();
    if (op == '*' || op == '/')
    {
      cin.get();
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

int calculate::factor()
{
  // a number
  int result = 0;
  char c = cin.peek();
  while (isdigit(c) || c == ' ')
  {
    if (isdigit(c))
    {
      result = 10 * result + c - '0';
      cin.get();
    }
    else cin.get();
    c = cin.peek();
  }
  return result;
}
