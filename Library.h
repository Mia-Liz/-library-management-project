#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Item.h"
#include "Book.h"
#include "CD.h"
#include "Member.h"
#include "Loan.h"

using namespace std;

class Library {
private:
    vector<Item*> items;
    vector<Member> members;
    vector<Loan> loans;

    Item* findItem(const string& itemId);
    Member* findMember(const string& memberId);
    int countActiveLoansForMember(const string& memberId) const;
    bool isItemAvailable(const string& itemId) const;
    Loan* findActiveLoan(const string& memberId, const string& itemId);

public:
    int count = 1;

    // Items
    void addBook(const Book& book);
    void addCD(const CD& cd);
    void listItems() const;
    Item* searchItemById(const string& id);  // ISBN for Book - UPC for CD
    Item* searchItemByTitle(const string& title);

    ~Library();  // Declare the destructor

    // Members
    void addMember(const Member& member);
    void listMembers() const;

    // Loans
    void listLoans(bool onlyActive = false) const;
    bool borrowItem(const string& memberId, const string& itemId, const string& borrowDate);
    bool returnItem(const string& memberId, const string& itemId, const string& returnDate);
    bool removeItem(const string& itemId);
    bool removeMember(const string& memberId);
};

#endif // LIBRARY_H

