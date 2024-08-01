// TEMPLATE FOR BOOK DATA
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

#include "AVLTree.h"
#include "Hash_Table.h"

class Book;

//forward declarations for overloaded functions
//comparison operators
bool operator<(const Book& lhs, const Book& rhs);
bool operator>(const Book& lhs, const Book& rhs);
bool operator<=(const Book& lhs, const Book& rhs);
bool operator>=(const Book& lhs, const Book& rhs);
bool operator==(const Book& lhs, const Book& rhs);
bool operator!=(const Book& lhs, const Book& rhs);

//output stream operator
std::ostream& operator<<(std::ostream& os, const Book& book);

//input stream operator
std::istream& operator>>(std::istream& is, Book& book);

class Book
{
private:
    int id;
    std::string title;
    std::string author;
    int publishing_year;
    bool isAvailable;
    int quantity;

public:
    //constructor
    Book(int id, const std::string& title, const std::string& author, int year, bool isAvailable, int quantity);

    //getter methods
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool getAvailability() const;
    int getQuantity() const;

    //setter methods
    void setId(int newId);
    void setTitle(std::string& newTitle);
    void setAuthor(std::string& newAuthor);
    void setYear(int newYear);
    void setAvailability(bool availability);
    void setQuantity(int newQuantity);

    //member functions
    void print() const;
    void updateAvailabilityStatus();
    //static because these methods arent instance specific
    static bool isBookAvailable(const HashTable<Book>& bookTable, const std::string& title);
    static void retrieveAndPrintAvailableBooks(HashTable<Book>& bookTable); 
    static void retrieveBooksByAuthor(const HashTable<Book>& bookTable);
    static void retrieveBooksByYear(const HashTable<Book>& bookTable);

};


#endif
