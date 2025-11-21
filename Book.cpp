#include "Book.h"

Book::Book(string t, string c, string i, int year)
    : Item (t, c, year), isbn(i) {}

string Book::getIsbn() const { return isbn; }

void Book::printInfo() const {
    cout << "Book - Title: " << title
        << " | Author: " << creator
        << " | ISBN: " << isbn
        << " | Year: " << publicationYear
        << endl;
}

