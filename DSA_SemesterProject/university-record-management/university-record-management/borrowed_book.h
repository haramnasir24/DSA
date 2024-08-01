// TEMPLATE FOR BORROWED BOOKS DATA
#ifndef BORROWED_BOOK_H
#define BORROWED_BOOK_H

#include "utilities.h"

#include "AVLTree.h"
#include "Hash_Table.h"

class BorrowedBook;

//forward declarations for overloaded operators
//comparison operators
bool operator<(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator>(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator==(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator!=(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator<=(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator>=(const BorrowedBook& lhs, const BorrowedBook& rhs);
//stream operators
std::ostream& operator<<(std::ostream& os, const BorrowedBook& book);
std::istream& operator>>(std::istream& is, BorrowedBook& book);

//class declaration
class BorrowedBook
{
private:
    int id;
    std::string title;
    std::string borrower;
    std::string issue_date;
    std::string due_date;

public:
    //constructor declaration
    BorrowedBook(int id, const std::string& title, const std::string& borrower, const std::string& issue_date, const std::string& due_date);

    //getter declarations
    int getId() const;
    std::string getTitle() const;
    std::string getBorrower() const;
    std::string getIssueDate() const;
    std::string getDueDate() const;

    //setter declarations
    void setId(int newId);
    void setTitle(const std::string& newTitle);
    void setBorrower(const std::string& newBorrower);
    void setIssueDate(const std::string& newIssueDate);
    void setDueDate(const std::string& newDueDate);

    //method declarations
    void print() const;
    //static because these methods arent instance specific
    static void borrowBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks);
    static void returnBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks);
    static std::vector<std::string> getBorrowedBooks(const HashTable<BorrowedBook>& borrowedBooks);
    static void retrieveBorrowerDetailsForBook(const HashTable<BorrowedBook>& borrowedBooks);

};



#endif // BORROWED_BOOK_H