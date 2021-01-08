
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


int main(){



    return 0;
}

