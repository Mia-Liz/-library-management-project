#include "Item.h"

Item::Item(string t, string c, int year)
    : title(t), creator(c), publicationYear(year) {}

Item::~Item() {} // Virtual destructor 

string Item::getTitle() const { return title; }
string Item::getCreator() const { return creator; }
int Item::getYear() const { return publicationYear; }

// Virtual function (empty base version)
void Item::printInfo() const {}