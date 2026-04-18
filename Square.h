// Square.h
// Square IS-A Rectangle whose length == width == side.
// Inherits calcArea() from Rectangle, so no override needed.
// setSide() must keep Rectangle's length and width in sync so the
// inherited calcArea() (and thus the base-class area) remains correct.
 
#ifndef SQUARE_H
#define SQUARE_H
 
#include "Rectangle.h"
#include <string>
 
class Square : public Rectangle {
private:
    double side;
 
public:
    // Constructor
    // Precondition:  s >= 0
    // Postcondition: Rectangle constructed with length=s, width=s;
    //                base-class name/area initialized.
    Square(double s, const std::string& n = "Square");
 
    // Updates side AND propagates to the inherited length/width via
    // Rectangle's setters, which trigger calcArea() automatically.
    void   setSide(double s);
    double getSide() const;
};
 
#endif
 