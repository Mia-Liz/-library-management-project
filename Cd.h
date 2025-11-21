#ifndef CD_H
#define CD_H

#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

class CD : public Item {
private:
    string upc;

public:
    CD(string t, string c, string u, int year);

    string getUpc() const;
    
    void printInfo() const override;
};

#endif // CD_H

