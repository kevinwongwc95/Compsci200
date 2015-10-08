#ifndef GeometryHomework_h
#define GeometryHomework_h

#include <iostream>
using std::ostream;

#include <cstdlib>

class Shape
{
protected:
  double const dimension1;
  double const dimension2;
  double const dimension3;
public:
  virtual ~Shape()
  {}
  Shape(const char* const token[]):dimension1(token[1]==0?0:atof(token[1])),dimension2(token[2]==0?0:atof(token[2])), dimension3(token[3]==0?0:atof(token[3]))
{}
  virtual void output(ostream&) const = 0;
};

//class definitions
struct Square:public Shape
{
  Square(const char* const token[]):Shape(token){}
  void output(ostream&) const;
};

namespace compsc
{
	struct Rectangle :public Shape
	{
		Rectangle(const char* const token[]) :Shape(token){}
		void output(ostream& out) const;
	};
}

struct Circle:public Shape
{
public:
  Circle(const char* const token[]):Shape(token){}
  void output(ostream& out) const;
};

struct Cube:public Square
{
public:
  Cube(const char* const token[]):Square(token)
  {
  }
  void output(ostream& out) const;
};

struct Prism:public compsc::Rectangle
{
  Prism(const char* const token[]):compsc::Rectangle(token)
  {
  }
  void output(ostream& out) const;

};

struct Cylinder:public Circle
{
  Cylinder(const char* const token[]):Circle(token){}
  void output(ostream& out) const;
};

ostream& reset(ostream& out);
ostream& set(ostream& out);
ostream& operator<<(ostream&, const Shape*);

#endif
