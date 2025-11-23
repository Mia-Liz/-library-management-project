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
    Loan(const string& i, const string& m, const string& bDate)
        : itemId(i), memberId(m), borrowDate(bDate), returnDate("") {}

    string getItemId() const { return itemId; }
    string getMemberId() const { return memberId; }
    string getBorrowDate() const { return borrowDate; }
    string getReturnDate() const { return returnDate; }
    bool isActive() const { return returnDate.empty(); }
    void setReturnDate(const string& rDate) { returnDate = rDate; }

    void printInfo() const {
        cout << "Item ID: " << itemId
             << " | Member ID: " << memberId
             << " | Borrow Date: " << borrowDate
             << " | Return Date: " << (returnDate.empty() ? "Not returned" : returnDate)
             << endl;
    }
};

#endif // LOAN_H


