#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual ~Figure() = default;
};

class Rectangle : public Figure {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    Rectangle operator+(const Rectangle& other) const {
        return Rectangle(1, this->getArea() + other.getArea()); 
    }
};

class Triangle : public Figure {
    double a, b, c; 
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double getArea() const override {
        double s = (a + b + c) / 2; 
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getPerimeter() const override {
        return a + b + c;
    }

    Triangle operator+(const Triangle& other) const {
        double newArea = this->getArea() + other.getArea();
        return Triangle(sqrt(newArea), sqrt(newArea), sqrt(newArea)); 
    }
};

class Circle : public Figure {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    Circle operator+(const Circle& other) const {
        double newArea = this->getArea() + other.getArea();
        return Circle(sqrt(newArea / M_PI)); 
    }
};

int main() {
    double rectWidth, rectHeight, triA, triB, triC, circRadius;
    cout << "Enter width and height of the rectangle: ";
    cin >> rectWidth >> rectHeight;
    cout << "Enter sides of the triangle (a, b, c): ";
    cin >> triA >> triB >> triC;
    cout << "Enter radius of the circle: ";
    cin >> circRadius;
    Figure* figures[3];
    figures[0] = new Rectangle(rectWidth, rectHeight);
    figures[1] = new Triangle(triA, triB, triC);
    figures[2] = new Circle(circRadius);
    
    for (int i = 0; i < 3; ++i) {
        cout << "Area: " << figures[i]->getArea() << ", Perimeter: " << figures[i]->getPerimeter() << endl;
    }
    
    double rectWidth1, rectHeight1, rectWidth2, rectHeight2;
    cout << "Enter width and height of the first rectangle for addition: ";
    cin >> rectWidth1 >> rectHeight1;
    cout << "Enter width and height of the second rectangle for addition: ";
    cin >> rectWidth2 >> rectHeight2;
    double triA1, triB1, triC1, triA2, triB2, triC2;
    cout << "Enter sides of the first triangle (a, b, c) for addition: ";
    cin >> triA1 >> triB1 >> triC1;
    cout << "Enter sides of the second triangle (a, b, c) for addition: ";
    cin >> triA2 >> triB2 >> triC2;
    double circRadius1, circRadius2;
    cout << "Enter radius of the first circle for addition: ";
    cin >> circRadius1;
    cout << "Enter radius of the second circle for addition: ";
    cin >> circRadius2;
    
    Rectangle rect1(rectWidth1, rectHeight1), rect2(rectWidth2, rectHeight2);
    Rectangle rectSum = rect1 + rect2;
    cout << "Sum of rectangles' areas: " << rectSum.getArea() << endl;

    Triangle tri1(triA1, triB1, triC1), tri2(triA2, triB2, triC2);
    Triangle triSum = tri1 + tri2;
    cout << "Sum of triangles' areas: " << triSum.getArea() << endl;

    Circle circ1(circRadius1), circ2(circRadius2);
    Circle circSum = circ1 + circ2;
    cout << "Sum of circles' areas: " << circSum.getArea() << endl;
    
    for (int i = 0; i < 3; ++i) {
        delete figures[i];
    }
    return 0;
}

