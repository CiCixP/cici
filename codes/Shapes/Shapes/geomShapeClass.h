#ifndef geomShapeClass_h
#define geomShapeClass_h

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>


class geometricShape
{
public:
  geometricShape();
  ~geometricShape();
  virtual std::string shape() = 0;
  virtual std::string stringify() = 0;
  virtual double computeArea() = 0;
  virtual void printOut(std::string shape, std::string parameters, double area);
};

class Rectangle
{
public:
  Rectangle(double base, double height);
  std::string shape();
  std::string stringify();
  double computeArea();
  double printOut(std::string shape, std::string parameters, double area);
protected:
  double _b;
  double _h;
};

class Triangle
{
public:
  Triangle(double base, double height);
  std::string shape();
  std::string stringify();
  double computeArea();
  double printOut(std::string shape, std::string parameters, double area);
protected:
  double _b;
  double _h;
};

class Circle
{
public:
  Circle(double radius);
  std::string shape();
  std::string stringify();
  double computeArea();
  double printOut(std::string shape, std::string parameters, double area);
protected:
  double _r;
};
#endif /* geomShapeClass_h */
