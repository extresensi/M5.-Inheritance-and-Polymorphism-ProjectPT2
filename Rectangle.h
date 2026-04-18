// Rectangle.h
// Concrete shape derived from BasicShape.
 
#ifndef RECTANGLE_H
#define RECTANGLE_H
 
#include "BasicShape.h"
#include <string>
 
class Rectangle : public BasicShape {
private:
    double length;
    double width;
 
public:
    // Constructor
    // Precondition:  l >= 0, w >= 0
    // Postcondition: members set; setName() and calcArea() called so that
    //                base-class state is consistent.
    Rectangle(double l, double w, const std::string& n = "Rectangle");
 
    // Computes length * width and stores it via BasicShape::setArea().
    void calcArea() override;
 
    // Setters must recompute area so the base class never holds stale data.
    void setLength(double l);
    void setWidth(double w);
 
    double getLength() const;
    double getWidth()  const;
};
 
#endif
 