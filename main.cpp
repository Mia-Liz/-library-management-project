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

    library.addMember(Member("Alice", "M01", 3));
    library.addMember(Member("Bob", "M02", 5));

    int option;
    do {
        cout << "===== Library Menu =====" << endl;
        cout << "1. List books" << endl;
        cout << "2. List members" << endl;
        cout << "3. List all loans" << endl;
        cout << "4. List active loans" << endl;
        cout << "5. Borrow a book" << endl;
        cout << "6. Return a book" << endl;
        cout << "7. Remove a book" << endl;
        cout << "8. Remove a member" << endl;
        cout << "9. Search book by ISBN" << endl;
        cout << "10. Search book by title" << endl;
        cout << "11. List CDs" << endl;
        cout << "0. Exit" << endl;
        cout << "Select option: ";
        cin >> option;

        if (option == 1) {
            library.listBooks();
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
            string memberId, isbn, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Book ISBN: ";
            cin >> isbn;
            cout << "Borrow date (YYYY-MM-DD): ";
            cin >> date;
            library.borrowBook(memberId, isbn, date);
            cout << endl;
        }
        else if (option == 6) {
            string memberId, isbn, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Book ISBN: ";
            cin >> isbn;
            cout << "Return date (YYYY-MM-DD): ";
            cin >> date;
            library.returnBook(memberId, isbn, date);
            cout << endl;
        }
        else if (option == 7) {
            string isbn;
            cout << "ISBN of book to remove: ";
            cin >> isbn;
            library.removeBook(isbn);
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
            string isbn;
            cout << "ISBN: ";
            cin >> isbn;
            Book* b = library.searchBookByIsbn(isbn);
            if (b) b->printInfo();
            else cout << "Book not found." << endl;
            cout << endl;
        }
        else if (option == 10) {
            string title;
            cout << "Title: ";
            cin >> ws;      
            getline(cin, title);
            Book* b = library.searchBookByTitle(title);
            if (b) b->printInfo();
            else cout << "Book not found." << endl;
            cout << endl;
        }
        else if (option == 11) {
            library.listCDs();
        }

    } while (option != 0);

    cout << "Goodbye!" << endl;
    return 0;
}