#include "geomShapeClass.h"

geometricShape::geometricShape() {}
geometricShape::~geometricShape() {}
void geometricShape::printOut(std::string shape, std::string parameters, double area)
{
  printf("I am a %s with parameters (%s) and an area of %f.", shape.c_str(), parameters.c_str(), area);
}

Rectangle::Rectangle(double base, double height) : _b(base), _h(height) {}
std::string Rectangle::shape()
{
  return "rectangle";
}
std::string Rectangle::stringify()
{
  std::ostringstream collect;
  collect << _b << ", " << _h;
  return collect.str();
}
double Rectangle::computeArea()
{
  return _b * _h;
}

Triangle::Triangle(double base, double height) : _b(base), _h(height) {}
std::string Triangle::shape()
{
  return "triangle";
}
std::string Triangle::stringify()
{
  std::ostringstream collect;
  collect << _b << ", " << _h;
  return collect.str();
}
double Triangle::computeArea()
{
  return _b * _h * 0.5;
}

Circle::Circle(double radius) : _r(radius) {}
std::string Circle::shape()
{
  return "circle";
}
std::string Circle::stringify()
{
  std::ostringstream collect;
  collect << _r;
  return collect.str();
}
double Circle::computeArea()
{
  return _r * _r * M_PI;
}
