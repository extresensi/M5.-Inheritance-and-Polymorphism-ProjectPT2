// BasicShape.cpp
// Implementation of the non-virtual members of the abstract BasicShape.
 
#include "BasicShape.h"
 
void        BasicShape::setArea(double area)               { this->area = area; }
void        BasicShape::setName(const std::string& name)   { this->name = name; }
double      BasicShape::getArea() const                    { return area; }
std::string BasicShape::getName() const                    { return name; }
 