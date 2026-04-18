// Circle.cpp
 
#include "Circle.h"
#include <cmath>
 
Circle::Circle(double x, double y, double r, const std::string& n)
    : xCenter(x), yCenter(y), radius(r)
{
    setName(n);     // store name in base class
    calcArea();     // compute and store area in base class
}
 
void Circle::calcArea() {
    const double PI = 3.14159265358979323846;
    setArea(PI * radius * radius);
}
 
// Setters - any change that affects the area must re-run calcArea().
void Circle::setXCenter(double x) { xCenter = x;               } // location only
void Circle::setYCenter(double y) { yCenter = y;               } // location only
void Circle::setRadius(double r)  { radius  = r; calcArea();   } // affects area
 
double Circle::getXCenter() const { return xCenter; }
double Circle::getYCenter() const { return yCenter; }
double Circle::getRadius()  const { return radius;  }
 