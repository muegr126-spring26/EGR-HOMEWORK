/*
Name:Antonio Butts Jr.
Assignment:HW7
Section:006
AI-Usage:Used AI to help with structure 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define Book struct
struct Book {
    string title;
    string author;
    int year;
    int pages;
};

int main() {
    vector<Book> books;

    // Input 5 books
    for (int i = 0; i < 5; i++) {
        Book b;

        cout << "Enter title: ";
        getline(cin, b.title);

        cout << "Enter author: ";
        getline(cin, b.author);

        cout << "Enter year published: ";
        cin >> b.year;

        cout << "Enter number of pages: ";
        cin >> b.pages;
        cin.ignore(); // clear newline

        books.push_back(b);
    }

    // Initialize tracking variables
    int earliestYear = books[0].year;
    int mostPages = books[0].pages;
    int totalPages = 0;

    // Output all books and compute stats
    cout << "\nBook List:\n";
    for (const Book& b : books) {
        cout << b.title << ", " << b.author << ", "
             << b.year << ", " << b.pages << endl;

        if (b.year < earliestYear) {
            earliestYear = b.year;
        }

        if (b.pages > mostPages) {
            mostPages = b.pages;
        }

        totalPages += b.pages;
    }

    double avgPages = (double)totalPages / books.size();

    // Output required stats
    cout << "\nmost pages: " << mostPages << endl;
    cout << "earliest published book: " << earliestYear << endl;
    cout << "average number of pages: " << avgPages << endl;

    return 0;
}