#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <iostream>

using namespace std;

class Loan {
private:
    string itemId;      // ISBN for Book or UPC for CD
    string memberId;    // who borrowed it
    string borrowDate;  // simple string for this example
    string returnDate;  // empty = still borrowed

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
