#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item {
protected:
    string title;
    string creator;
    int publicationYear;

public:
    Item(string t, string c, int year);
    string getTitle() const;
    string getCreator() const;
    int getYear() const;

    virtual void printInfo() const = 0;

    virtual ~Item() {}
};

#endif // ITEM_H