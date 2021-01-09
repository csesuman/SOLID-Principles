/*Responsibility is considered to be one reason to change.
Algorithm
Robert C. Martin has defined the OCP in his book, Agile Software Development: Principles, Patterns, and Practices (Prentice Hall, 2003), as follows:

Open for extension – This means that the behavior of the module can be extended. As the requirements of the application change, we are able to extend the module with new behaviors that satisfy those changes. In other words, we are able to change what the module does.

Closed for modification – Extending the behavior of a module does not result in changes to the source or binary code of the module. The binary executable version of the module, whether in a linkable library, a DLL, or a Java .jar, remains untouched.
*/

#include<bits/stdc++.h>

using namespace std;

const double pi = 2 * cos(0.0);

class Shape {
public:
    virtual double Area() = 0;
    virtual ~Shape() {

    }
};

class Rectangle : public Shape {

private:
    double width;
    double height;
public:
    void setWitdth(double width) {
        this->width = width;
    }

    void setHeight(double height) {
        this->height = height;
    }

    double Area() override {
        return width * height;
    }

    ~Rectangle() {
        this->~Shape();
    }
};


class Circle : public Shape {

private:
    double radius;
public:
    void setRadius(double radius) {
        this->radius = radius;
    }
    double Area() override {
        return radius*radius*pi;
    }
};

double getArea(vector<Shape*> shapes) {

    double area = 0;
    for(auto shape: shapes) {
        area += shape->Area();
    }

    return area;
}

template<typename Base,typename T>
inline bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}


double getAreaInBadWay(vector<Shape*> shapes) {

    double area = 0;
    // if no Area method we will use manual way to calculate area..
    for(auto shape: shapes) {

        if(instanceof<Rectangle>(shape)) {
            Rectangle *rectangle = (Rectangle *) &shape;
            area+= rectangle->Area();
        }
        else if(instanceof<Circle>(shape)) {
            Circle *circle = (Circle *) &circle;

            area += circle->Area();
        }
    }

    return area;
}

int main(){



    // This is Good Way1
    Rectangle *rectangle = new Rectangle();
    rectangle->setHeight(5);
    rectangle->setWitdth(10);


    Circle *circle = new Circle();
    circle->setRadius(10);



    vector<Shape*> shapes;

    shapes.push_back(rectangle);
    shapes.push_back(circle);
    cout<<"Total area = " << getArea(shapes);


    return  0;
}
