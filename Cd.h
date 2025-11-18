#ifndef CD_H
#define CD_H

#include <string>
#include <iostream>

using namespace std;

class CD {
private:
    string title;
    string artist;
    string id;    // unique CD ID
    int year;

public:
    CD(string t, string a, string id, int y);
    string getId() const;
    string getTitle() const;
    string getArtist() const;
    int getYear() const;

    void printInfo() const;
};

#endif

