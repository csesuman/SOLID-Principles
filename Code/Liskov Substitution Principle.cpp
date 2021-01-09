
/*Subtypes must be substitutable for their base types.

Algorithm
Substitutability is a principle in object-oriented programming stating that, in a computer program,
 if S is a subtype of T, then objects of type T may be replaced with objects of type S
*/

#include<bits/stdc++.h>

using namespace std;

// Bad Example
class Bird_Temp{
public:
    virtual void fly() = 0;
};

class Duck_Temp : Bird_Temp {

};

class Ostrich_Temp : Bird_Temp { // Ostrich can not fly

};

// Good Way

class Bird{
public:

};

class FlyingBirds : Bird
{
public:
    virtual void fly() = 0;
};

class Duck : FlyingBirds {

};

class Ostrich : Bird { // Ostrich can not fly

};

// Again Rule Violation Example

 // Violation of Likov's Substitution Principle
class Rectangle {

protected:
    int width;
    int height;

public:
    void setWidth(int width) {
        this->width = width;
    }

    void setHeight(int height) {
        this->height = height;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    int getArea() {
        return width * height;
    }
};

class Square : public Rectangle {

public:
    void setWidth(int width) {
        this->width = width;
        this->height = width;
    }

    void setHeight(int height) {
        this->width = height;
        this->height = height;
    }

};

class LspTest {

public:
    static Rectangle getNewRectangle() {
        // it can be an object returned by some factory ...
        return Square();
    }

//    static void main() {
//        Rectangle r = LspTest.getNewRectangle();
//
//        r.setWidth(5);
//        r.setHeight(10);
//        // user knows that r it's a rectangle.
//        // It assumes that he's able to set the width and height as for the base
//        // class
//
////        System.out.println(r.getArea());
//        // now he's surprised to see that the area is 100 instead of 50.
//    }
};



int main(){

    Rectangle rec = LspTest::getNewRectangle();

    rec.setHeight(5);
    rec.setWidth(10);


    cout << "Area is " << rec.getArea() << endl;

    // this is wrong output




    return 0;
}

