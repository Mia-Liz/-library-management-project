#include "CD.h"

CD::CD(string t, string c, string u, int year)
    : Item (t, c, year), upc(u) {}

string CD::getUpc() const { return upc; }

void CD::printInfo() const {
    cout << "CD - Title: " << title
        << " | Artist: " << creator
        << " | UPC: " << upc
        << " | Year: " << publicationYear 
        << endl;
}

