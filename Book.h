#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

class Book : public Item {
private:
    string isbn;

public:
    Book(string t, string c, string i, int year);
    
    string getIsbn() const;

    void printInfo() const override;
};

#endif // BOOK_H

