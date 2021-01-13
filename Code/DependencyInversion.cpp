/** two dependencies:

the high-level module depends on the abstraction, and
the low-level depends on the same abstraction.
*/

/**

1. High level modules should not depend on low level modules; both should depend on abstractions.

2. Abstractions should not depend on details. Details should depend upon abstraction.
*/

#include<bits/stdc++.h>

using namespace std;

class Book {
private:
    string title;
    int number;
public:
    Book(){}
    Book(string title,int number) {
        this->title = title;
        this->number = number;
    }

    void display() {
        cout<<"Book Name: " << this->title << " Number: " << this->number << endl;
    }
};

// BAD WAY
class IsbnGenerator {

public:
    int generateNumber() {
        return 500000 +  (rand() % 10000) ;
    }
};

class BookService {
private:
    IsbnGenerator *isbn = new IsbnGenerator();
 public:
     Book *createBook(string title) {
         return new Book(title, isbn->generateNumber());
     }
 };


 /**/

class IGenerator {
public:
    virtual int generateNumber() = 0;
};

class FirstGenerator : public IGenerator {

public:
    int generateNumber() override {
        return 7000000 + (rand()%1000);
    }
};

class SecondGenerator : public IGenerator {

public:
    SecondGenerator(){}
    int generateNumber() override {
        return 8000000 + (rand()%1000);
    }
};

class BookServiceGood  {

private:
    IGenerator *isbn;
public:

    void setGenerator(IGenerator *isbn) {
        this->isbn = isbn;
    }

    Book *createBook(string title) {
        return new Book(title, isbn->generateNumber());
    }
 };


int main() {
    srand (time(NULL));

    BookServiceGood* service = new BookServiceGood();
    IGenerator *isbn = new SecondGenerator();

    service->setGenerator(new SecondGenerator());
    Book *book = service->createBook("Horro Book 1");
    book->display();

    service->setGenerator(new FirstGenerator());
    book = service->createBook("Horro Book 2");
    book->display();

    return 0;
}
