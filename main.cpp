#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

// =========================
// main - Simple menu
// =========================
int main() {
    Library library;

    // Preload some sample data
    library.addBook(Book("Clean Code", "Robert C. Martin", "1111", 2008));
    library.addBook(Book("The Pragmatic Programmer", "Andrew Hunt", "2222", 1999));
    library.addBook(Book("Design Patterns", "Gamma et al.", "3333", 1994));

    library.addCD(CD("Abbey Road", "The Beatles", "4444", 1969));
    library.addCD(CD("Rumours", "Fleetwood Mac", "5555", 1977));
    library.addCD(CD("Thriller", "Michael Jackson", "6666", 1982));

    library.addMember(Member("Alice", "M01", 3));
    library.addMember(Member("Bob", "M02", 5));

    int option;
    do {
        cout << "===== Library Menu =====" << endl;
        cout << "1. List items" << endl;
        cout << "2. List members" << endl;
        cout << "3. List all loans" << endl;
        cout << "4. List active loans" << endl;
        cout << "5. Borrow an item" << endl;
        cout << "6. Return an item" << endl;
        cout << "7. Remove an item" << endl;
        cout << "8. Remove a member" << endl;
        cout << "9. Search item by ID (ISBN/UPC)" << endl;
        cout << "10. Search item by title" << endl;
        cout << "0. Exit" << endl;
        cout << "Select option: ";
        cin >> option;

        if (option == 1) {
            library.listItems();
        }
        else if (option == 2) {
            library.listMembers();
        }
        else if (option == 3) {
            library.listLoans(false);
        }
        else if (option == 4) {
            library.listLoans(true);
        }
        else if (option == 5) {
            string memberId, itemId, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Item ID (ISBN/UPC): ";
            cin >> itemId;
            cout << "Borrow date (YYYY-MM-DD): ";
            cin >> date;
            library.borrowItem(memberId, itemId, date);
            cout << endl;
        }
        else if (option == 6) {
            string memberId, itemId, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Item ID (ISBN/UPC): ";
            cin >> itemId;
            cout << "Return date (YYYY-MM-DD): ";
            cin >> date;
            library.returnItem(memberId, itemId, date);
            cout << endl;
        }
        else if (option == 7) {
            string itemId;
            cout << "ID (ISBN/UPC) of item to remove: ";
            cin >> itemId;
            library.removeItem(itemId);
            cout << endl;
        }
        else if (option == 8) {
            string memberId;
            cout << "Member ID to remove: ";
            cin >> memberId;
            library.removeMember(memberId);
            cout << endl;
        }
        else if (option == 9) {
            string itemId;
            cout << "Item ID (ISBN/UPC): ";
            cin >> itemId;
            Item* b = library.searchItemById(itemId);
            if (b) b->printInfo();
            else cout << "Item not found." << endl;
            cout << endl;
        }
        else if (option == 10) {
            string title;
            cout << "Title: ";
            cin >> ws;      
            getline(cin, title);
            Item* b = library.searchItemByTitle(title);
            if (b) b->printInfo();
            else cout << "Item not found." << endl;
            cout << endl;
        }

    } while (option != 0);

    cout << "Goodbye!" << endl;
    return 0;
}