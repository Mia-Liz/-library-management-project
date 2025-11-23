#include "Library.h"
#include <iostream>

using namespace std;

// ==== INTERNAL HELPERS ====

// Find item by ISBN (book) or UPC (CD)
Item* Library::findItem(const string& itemId) {
    for (auto item : items) {
        // Book
        if (Book* b = dynamic_cast<Book*>(item))
            if (b->getIsbn() == itemId)
                return b;

        // CD
        if (CD* c = dynamic_cast<CD*>(item))
            if (c->getUpc() == itemId)
                return c;
    }
    return nullptr;
}

// Find a member by ID
Member* Library::findMember(const string& memberId) {
    for (auto& member : members)
        if (member.getId() == memberId)
            return &member;

    return nullptr;
}

// Count active loans for member
int Library::countActiveLoansForMember(const string& memberId) const {
    int count = 0;

    for (const auto& loan : loans)
        if (loan.getMemberId() == memberId && loan.isActive())
            count++;

    return count;
}

// Check if an item is available
bool Library::isItemAvailable(const string& itemId) const {
    for (const auto& loan : loans)
        if (loan.getItemId() == itemId && loan.isActive())
            return false;

    return true;
}

// Find currently active loan for that item & member
Loan* Library::findActiveLoan(const string& memberId, const string& itemId) {
    for (auto& loan : loans)
        if (loan.getMemberId() == memberId &&
            loan.getItemId() == itemId &&
            loan.isActive())
            return &loan;

    return nullptr;
}

// ==== ITEMS ====

// Add items (books or CDs)
void Library::addBook(const Book& book) {
    items.push_back(new Book(book));
}

void Library::addCD(const CD& cd) {
    items.push_back(new CD(cd));
}

// List all items
void Library::listItems() const {
    cout << "=== Library Items ===" << endl;

    if (items.empty()) {
        cout << "No items in the library." << endl << endl;
        return;
    }

    for (auto item : items)
        item->printInfo();

    cout << endl;
}

// Search items
Item* Library::searchItemById(const string& id) {
    return findItem(id);
}

Item* Library::searchItemByTitle(const string& title) {
    for (auto item : items)
        if (item->getTitle() == title)
            return item;

    return nullptr;
}

// ==== MEMBERS ====

// Add members
void Library::addMember(const Member& member) {
    members.push_back(member);
}

// List members
void Library::listMembers() const {
    cout << "=== Members ===" << endl;

    if (members.empty()) {
        cout << "No registered members." << endl << endl;
        return;
    }

    for (const auto& member : members)
        member.printInfo();

    cout << endl;
}

// ==== LOANS ====

// List loans
void Library::listLoans(bool onlyActive) const {
    cout << (onlyActive ? "=== Active Loans ===" : "=== All Loans ===") << endl;

    if (loans.empty()) {
        cout << "No loans found." << endl << endl;
        return;
    }

    for (const auto& loan : loans)
        if (!onlyActive || loan.isActive())
            loan.printInfo();

    cout << endl;
}

// Borrow book OR CD
bool Library::borrowItem(const string& memberId,
                        const string& itemId,
                        const string& borrowDate) 
{
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Item* item = findItem(itemId);
    if (!item) {
        cout << "Item not found." << endl;
        return false;
    }

    if (!isItemAvailable(itemId)) {
        cout << "Item is already on loan." << endl;
        return false;
    }

    if (countActiveLoansForMember(memberId) >= member->getMaxBooks()) {
        cout << "Member reached the maximum number of active loans." << endl;
        return false;
    }

    loans.push_back(Loan(itemId, memberId, borrowDate));
    cout << "Loan successful." << endl;
    return true;
}

// Return item
bool Library::returnItem(const string& memberId,
                        const string& itemId,
                        const string& returnDate) 
{
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Item* item = findItem(itemId);
    if (!item) {
        cout << "Item not found." << endl;
        return false;
    }

    Loan* loan = findActiveLoan(memberId, itemId);
    if (!loan) {
        cout << "No active loan found." << endl;
        return false;
    }

    loan->setReturnDate(returnDate);
    cout << "Item returned successfully." << endl;
    return true;
}

// ==== REMOVE ====

// Remove book OR CD
bool Library::removeItem(const string& itemId) {
    // Prevent deletion if item is on loan
    for (const auto& loan : loans)
        if (loan.getItemId() == itemId && loan.isActive()) {
            cout << "Item cannot be removed — it is currently on loan." << endl;
            return false;
        }

    for (auto it = items.begin(); it != items.end(); ++it) {
        Book* b = dynamic_cast<Book*>(*it);
        if (b && b->getIsbn() == itemId) {
            delete *it;
            items.erase(it);
            cout << "Book removed successfully." << endl;
            return true;
        }

        CD* c = dynamic_cast<CD*>(*it);
        if (c && c->getUpc() == itemId) {
            delete *it;
            items.erase(it);
            cout << "CD removed successfully." << endl;
            return true;
        }
    }

    cout << "Item not found." << endl;
    return false;
}

// Remove a member
bool Library::removeMember(const string& memberId) {
    for (const auto& loan : loans)
        if (loan.getMemberId() == memberId && loan.isActive()) {
            cout << "Cannot remove member — active loans exist." << endl;
            return false;
        }

    for (auto it = members.begin(); it != members.end(); ++it)
        if (it->getId() == memberId) {
            members.erase(it);
            cout << "Member removed successfully." << endl;
            return true;
        }

    cout << "Member not found." << endl;
    return false;
}

// ==== DESTRUCTOR ====
Library::~Library() {
    for (auto item : items)
        delete item;
}
