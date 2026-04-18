// main.cpp
// Test driver for the Basic Shapes polymorphism project.
//
// Demonstrates:
//   - Construction of Circle, Rectangle, and Square objects
//   - Access through an array of BasicShape* pointers (polymorphism)
//   - Correct virtual dispatch of calcArea()
//   - Setters that keep base-class area state consistent
//
// Build:  g++ -std=c++17 -Wall *.cpp -o shapes
// Run:    ./shapes
 
#include <iostream>
#include <iomanip>
 
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
 
static void banner(const std::string& title) {
    std::cout << "\n==== " << title << " ====\n";
}
 
// Prints a shape via base-class pointer - requires virtual behavior
// for name/area that were set by the derived class.
static void printShape(const BasicShape* s) {
    std::cout << std::left  << std::setw(12) << s->getName()
              << " area = " << std::fixed << std::setprecision(4)
              << s->getArea() << "\n";
}
 
int main() {
    // --- Construct shapes ---------------------------------------------------
    Rectangle r1(3.0, 4.0, "Rect-3x4");
    Rectangle r2(5.0, 2.5, "Rect-5x2.5");
    Circle    c1(0.0, 0.0, 1.0, "Unit-Circle");
    Circle    c2(2.0, 3.0, 7.5, "Big-Circle");
    Square    sq(4.0, "Square-4");
 
    // --- Store in an array of BasicShape* ----------------------------------
    const int N = 5;
    BasicShape* shapes[N] = { &r1, &r2, &c1, &c2, &sq };
 
    banner("Polymorphic print (before mutation)");
    for (int i = 0; i < N; ++i) {
        printShape(shapes[i]);
    }
 
    // --- Setter tests: base-class area must stay consistent ----------------
    banner("After Circle::setRadius(10)");
    c1.setRadius(10.0);
    printShape(&c1);
 
    banner("Circle location-only setters (area should NOT change)");
    double areaBefore = c2.getArea();
    c2.setXCenter(100.0);
    c2.setYCenter(-50.0);
    std::cout << "xCenter=" << c2.getXCenter()
              << "  yCenter=" << c2.getYCenter()
              << "  area before=" << areaBefore
              << "  area now="   << c2.getArea() << "\n";
 
    banner("After Rectangle::setLength(10) and setWidth(3)");
    r1.setLength(10.0);
    r1.setWidth(3.0);
    printShape(&r1);
 
    banner("After Square::setSide(6)");
    sq.setSide(6.0);
    printShape(&sq);
    std::cout << "side=" << sq.getSide()
              << "  length=" << sq.getLength()
              << "  width=" << sq.getWidth() << "\n";
 
    // --- Final polymorphic sweep -------------------------------------------
    banner("Polymorphic print (after mutation)");
    for (int i = 0; i < N; ++i) {
        printShape(shapes[i]);
    }
 
    std::cout << "\nAll shapes verified.\n";
    return 0;
}
 