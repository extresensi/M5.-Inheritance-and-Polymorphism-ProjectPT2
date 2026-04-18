// Square.cpp
 
#include "Square.h"
 
Square::Square(double s, const std::string& n)
    : Rectangle(s, s, n),   // forward length=s, width=s to Rectangle
      side(s)
{
    // Rectangle's constructor already called setName("Rectangle") then we
    // override with the correct name here.
    setName(n);
}
 
void Square::setSide(double s) {
    side = s;
    // Keep the inherited Rectangle length/width in sync.  Each of these
    // setters invokes calcArea(), so the base-class area stays correct.
    setLength(s);
    setWidth(s);
}
 
double Square::getSide() const { return side; }
 