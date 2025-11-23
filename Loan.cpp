#include "Loan.h"
#include <iostream>

Loan::Loan(const string& i, const string& m, const string& bDate)
    : itemId(i), memberId(m), borrowDate(bDate), returnDate("") {}

string Loan::getItemId() const {
    return itemId;
}

string Loan::getMemberId() const {
    return memberId;
}

string Loan::getBorrowDate() const {
    return borrowDate;
}

string Loan::getReturnDate() const {
    return returnDate;
}

bool Loan::isActive() const {
    return returnDate.empty();
}

void Loan::setReturnDate(const string& rDate) {
    returnDate = rDate;
}

void Loan::printInfo() const {
    cout << "Loan - Item ID: " << itemId
         << " | Member ID: " << memberId
         << " | Borrowed: " << borrowDate
         << " | Returned: "
         << (returnDate.empty() ? "NOT RETURNED" : returnDate)
         << endl;
}


