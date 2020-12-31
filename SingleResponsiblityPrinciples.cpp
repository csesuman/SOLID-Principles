#include<bits/stdc++.h>

using namespace std;

// Before Refacetor
class IUser_With_MultipleResponsiblity {
public:
    // pure virual function
    virtual bool Login(string userName, string password) = 0;
    virtual bool Resigter(string username, string password, string email) = 0;

    virtual bool LogError(string error) = 0;
    virtual bool sendEmail(string emailContent) = 0;
};

// Single Responsiblity

class IUser{
public:
    // pure virual function
    virtual bool Login(string userName, string password) = 0;
    virtual bool Resigter(string username, string password, string email) = 0;
};

class IEmail {
public:
   virtual bool sendEmail(string emailContent) = 0;
};

class ILogger {
public:
    virtual bool LogError(string error) = 0;
};

int main(){



    return 0;
}
