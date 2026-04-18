// Circle.h
// Concrete shape derived from BasicShape.
 
#ifndef CIRCLE_H
#define CIRCLE_H
 
#include "BasicShape.h"
#include <string>
 
class Circle : public BasicShape {
private:
    double xCenter;
    double yCenter;
    double radius;
 
public:
    // Constructor
    // Precondition:  r >= 0
    // Postcondition: members set; setName() and calcArea() called so that
    //                base-class state is consistent.
    Circle(double x, double y, double r, const std::string& n = "Circle");
 
    // Computes pi * r^2 and stores it via BasicShape::setArea().
    // Precondition:  radius is set
    // Postcondition: base-class area updated
    void calcArea() override;
 
    // Setters update the affected member then re-trigger calcArea() so
    // base-class area never goes stale.
    void setXCenter(double x);
    void setYCenter(double y);
    void setRadius(double r);
 
    double getXCenter() const;
    double getYCenter() const;
    double getRadius()  const;
};
 
#endif
 