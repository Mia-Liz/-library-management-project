#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <iostream>

using namespace std;

class Loan {
private:
    string itemId;
    string memberId;
    string borrowDate;
    string returnDate;

public:
    Loan(const string& i, const string& m, const string& bDate);

    string getItemId() const;
    string getMemberId() const;
    string getBorrowDate() const;
    string getReturnDate() const;

    bool isActive() const;
    void setReturnDate(const string& rDate);

    void printInfo() const;
};

#endif
