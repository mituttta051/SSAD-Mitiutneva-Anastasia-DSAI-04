#include <iostream>
using namespace std;
class Shape {
    virtual const double area() = 0;
    virtual const double  perimeter() = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) {
      this->height = height;
      this->width = width;
    };
    const double area() override {
        return width*height;
    }
    const double perimeter() override {
        return 2*(width+height);
    }
};
class Circle : public Shape {
private:
    double radius;
    const double pi = 3.14;
public:
    Circle(double radius) {
        this->radius = radius;
    }

    const double area() override {
        return pi*radius*radius;
    }
    const double perimeter() override {
        return 2*pi*radius;
    }

};

int main()
{
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);

    Shape *shape = &rectangle;

    // Demonstrate static casting [1]

    Rectangle* rectPtr = static_cast<Rectangle*>(shape);


    // Demonstrate dynamic casting [2]
    if (Circle* circlePtr = dynamic_cast<Circle*>(shape)) {

        cout << "shape is a Circle";
    } else {
        cout << "shape is not a Circle";
    }

    // Demonstrate const casting [3]
    double area = const_cast<Rectangle*>(rectPtr)->area();


    int intValue = 42;
    // Demonstrate reinterpret casting [4]
    double doubleValue = reinterpret_cast<double&>(intValue);

    return 0;
}


