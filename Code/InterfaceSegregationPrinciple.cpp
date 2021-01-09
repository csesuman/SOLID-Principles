/*
Rules
1.  a client should not be exposed to methods it doesn’t need.
*/

#include<bits/stdc++.h>

using namespace std;

// Before Interface segregation
class IPets_withAll {
public:
    // pure virual function
    virtual bool isFriendly() = 0;
    virtual string getName() = 0;
    virtual void bark() = 0;
};

class Okay_Dog : IPets_withAll { // only okay this class

//    virtual bool isFriendly() = 0;
//    virtual string getName() = 0;
//    virtual void bark() = 0;
};

class Not_okay_Cat : IPets_withAll {

//    virtual bool isFriendly() = 0;
//    virtual string getName() = 0;
//    virtual void bark() = 0; // doesn't need this. need meow()
};

class Not_okay_Rabbit: IPets_withAll {

//    virtual bool isFriendly() = 0;
//    virtual string getName() = 0;
//    virtual void bark() = 0; // doesn't need this.
};

// problem Exists as
/*
Dogs needs all of abter
*/


// After Interface Seggregation

class IPet {
public:
    // pure virual function
    virtual bool isFriendly() = 0;
    virtual string getName() = 0;
};

class IPetRabbit: IPet {
public:

};

class IPetDog: IPet {
public:
    virtual void bark() = 0;
};

class IPetCat: IPet {
public:
    virtual void meow() = 0;
};




int main(){

//    Dog dog;

    return 0;
}
