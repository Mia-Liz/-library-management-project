#include "CD.h"

CD::CD(string t, string a, string i, int y)
    : title(t), artist(a), id(i), year(y) {}

string CD::getId() const { return id; }
string CD::getTitle() const { return title; }
string CD::getArtist() const { return artist; }
int CD::getYear() const { return year; }

void CD::printInfo() const {
    cout << "CD - Title: " << title
         << " | Artist: " << artist
         << " | ID: " << id
         << " | Year: " << year << endl;
}

