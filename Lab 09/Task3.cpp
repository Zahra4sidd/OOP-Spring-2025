// Book.h
#ifndef BOOK
#define BOOK
#include <string>
using namespace std;
class Book{
    private:
    string title, author, ISBN;
    public:
    Book(string t, string a, string i);
    string getTitle();
    string getAuthor();
    string getISBN();   
};
class Library {
private:
    Book* books[100];
    int count;

public:
    Library();
    ~Library();
    void addBook(Book* book);
    void removeBook(string isbn);
    Book* searchBook(string title);
};
#endif
// Book.cpp
#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, string a, string i):title(t),author(a),ISBN(i){}
string Book::getTitle(){
    return title;
}
string Book::getAuthor(){
    return author;
}
string Book::getISBN(){
    return ISBN;
}

Library::Library() {
    count = 0;
}

Library::~Library() {
    for (int i = 0; i < count; i++) {
        delete books[i];
    }
}

void Library::addBook(Book* book) {
    if (count < 100) {
        books[count++] = book;
        cout << "Book added: " << book->getTitle() << endl;
    } else {
        cout << "Library is full!\n";
    }
}

void Library::removeBook(string isbn) {
    for (int i = 0; i < count; i++) {
        if (books[i]->getISBN() == isbn) {
            delete books[i];
            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }
            count--;
            cout << "Book removed with ISBN: " << isbn << endl;
            return;
        }
    }
    cout << "Book not found with ISBN: " << isbn << endl;
}

Book* Library::searchBook(string title) {
    for (int i = 0; i < count; i++) {
        if (books[i]->getTitle() == title) {
            return books[i];
        }
    }
    return nullptr;
}
// main.cpp
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

int main() {
    Library lib;
    lib.addBook(new Book("1984", "George Orwell", "9780451524935"));
    lib.addBook(new Book("Brave New World", "Aldous Huxley", "9780060850524"));

    Book* found = lib.searchBook("1984");
    if (found) {
        cout << "\nFound Book:\n";
        cout << "Title: " << found->getTitle() << endl;
        cout << "Author: " << found->getAuthor() << endl;
        cout << "ISBN: " << found->getISBN() << endl;
    } else {
        cout << "Book not found.\n";
    }
    lib.removeBook("9780060850524");

    return 0;
}
