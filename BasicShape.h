// BasicShape.h
// Abstract base class for all shapes.
// Stores shared state (name and computed area) and declares a pure
// virtual calcArea() that every concrete derived class must provide.
 
#ifndef BASICSHAPE_H
#define BASICSHAPE_H
 
#include <string>
 
class BasicShape {
private:
    double      area;   // computed area (set by derived classes)
    std::string name;   // human-readable shape name
 
public:
    // Virtual destructor so deletion through a BasicShape* frees derived parts.
    virtual ~BasicShape() = default;
 
    // Mutators / accessors for shared state
    // Precondition:  area >= 0 for setArea
    // Postcondition: member updated / returned
    void        setArea(double area);
    void        setName(const std::string& name);
    double      getArea() const;
    std::string getName() const;
 
    // Pure virtual: each concrete shape must implement its own area formula
    // and store the result via setArea().
    // Precondition:  object is fully constructed
    // Postcondition: base-class area member is updated
    virtual void calcArea() = 0;
};
 
#endif
 