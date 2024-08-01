#include "borrowed_book.h"

//member functions of borrowed book class
//constructor for borrowed book instance
BorrowedBook::BorrowedBook(int id, const std::string& title, const std::string& borrower,
    const std::string& issue_date, const std::string& due_date)
    : id(id), title(title), borrower(borrower), issue_date(issue_date), due_date(due_date) {}

//getter functions
int BorrowedBook::getId() const { return id; }
std::string BorrowedBook::getTitle() const { return title; }
std::string BorrowedBook::getBorrower() const { return borrower; }
std::string BorrowedBook::getIssueDate() const { return issue_date; }
std::string BorrowedBook::getDueDate() const { return due_date; }

//setter functions
void BorrowedBook::setId(int newId) { id = newId; }
void BorrowedBook::setTitle(const std::string& newTitle) { title = newTitle; }
void BorrowedBook::setBorrower(const std::string& newBorrower) { borrower = newBorrower; }
void BorrowedBook::setIssueDate(const std::string& newIssueDate) { issue_date = newIssueDate; }
void BorrowedBook::setDueDate(const std::string& newDueDate) { due_date = newDueDate; }

//method to print out borrowed book details
void BorrowedBook::print() const
{
    std::cout << "ID: " << id << "\nTitle: " << title << "\nBorrowed by: " << borrower << "\nIssue Date: "
        << issue_date << "\nDue Date:" << due_date;
    std::cout << std::endl;
}

//funtion for borrowing a book from the inventory
void BorrowedBook::borrowBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks)
{   std::string bookTitle;

    //prompt the user for a book name
    std::cout << "Enter the name of the book you want to borrow: ";
    cin.clear(); // Clear any errors on the stream, if any.
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore up to the newline
    std::getline(std::cin, bookTitle);

    //get the AVLTree corresponding to the book title
    AVLTree<Book>* tree = bookInventory.search(bookTitle); //hash table search function

    //loop through each book in the tree if it is found
    if (tree) {
        std::vector<Book> books = tree->getValues();    //storing the vector of books (Book object)
        for (int i = 0; i < books.size(); i++)  //iterate over said vector
        {
            Book& book = books[i];  //creating a reference to each book object at current index
            //check if this is the book user wants to borrow
            if (book.getTitle() == bookTitle && book.getAvailability() && book.getQuantity() > 0) {
                std::cout << "\nThe book " << bookTitle << " is available.You can borrow it.\n";

                //reduce the quantity by one
                book.setQuantity(book.getQuantity() - 1);

                //get user name
                std::string userName;
                std::cout << "Enter your name: ";
                std::getline(std::cin, userName);

                //get the dates
                std::string issue_date = getCurrentDate();
                std::string due_date = getTwoWeeksLaterDate();

                //create a BorrowedBook object and add it to the hash table
                BorrowedBook newBorrowedBook(book.getId(), book.getTitle(), userName, issue_date, due_date);
                borrowedBooks.insert(bookTitle, newBorrowedBook);

                std::cout << "The due date for the book would be " << due_date << std::endl;
                return;
            }
        }
    }

    //if the book is not found in the inventory
    std::cout << "\nSorry! The book you requested is not available.\n";
}

//function to return a book to the library
void BorrowedBook::returnBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks) {
    std::string bookTitle;
    std::string userName;

    //prompt the user for a book name
    std::cout << "Enter the name of the book you want to return: ";
    cin.clear(); // Clear any errors on the stream, if any.
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore up to the newline
    std::getline(std::cin, bookTitle);

    //check if the book exists in the book inventory
    AVLTree<Book>* bookTree = bookInventory.search(bookTitle);
    if (!bookTree)
    {
        std::cout << "Invalid attempt.\nEntered book does not exist in borrowed books inventory.\n";
        return;
    }

    //prompt the user for their name
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);

    //search for the borrowed book in the 'borrowedBooks' hash table
    AVLTree<BorrowedBook>* borrowedBookTree = borrowedBooks.search(bookTitle);

    //loop through each borrowed book in the tree if tree is found
    if (borrowedBookTree)
    {
        std::vector<BorrowedBook> borrowedBooksVector = borrowedBookTree->getValues();
        for (int i = 0; i < borrowedBooksVector.size(); i++) {
            BorrowedBook& borrowedBook = borrowedBooksVector[i];

            // Check if this is the borrowed book that the user wants to return
            if (borrowedBook.getTitle() == bookTitle && borrowedBook.getBorrower() == userName) {
                std::cout << "\nBorrowed book found. You can return it.\n";

                //remove the returned book from the 'borrowedBooks' hash table
                borrowedBooks.remove(bookTitle, borrowedBook);

                // Increase the quantity of the book in the 'bookInventory' hash table
                AVLTree<Book>* bookTree = bookInventory.search(bookTitle);

                //loop through each book in the tree if tree is found
                if (bookTree)
                {
                    std::vector<Book> books = bookTree->getValues();
                    for (int j = 0; j < books.size(); j++)
                    {
                        Book& book = books[j];

                        //check if this is the book that was returned
                        if (book.getTitle() == bookTitle)
                        {
                            book.setQuantity(book.getQuantity() + 1);
                            book.updateAvailabilityStatus();
                            return;
                        }
                    }
                }
            }
        }
    }

    //if the borrowed book is not found
    std::cout << "Sorry! This book has not yet been borrowed.\n";
}

std::vector<std::string> BorrowedBook::getBorrowedBooks(const HashTable<BorrowedBook>& borrowedBooks) {
    std::vector<std::string> borrowedBookTitles;

    for (const auto& item : borrowedBooks.getItems()) {
        AVLTree<BorrowedBook>* avlTree = item->getHashValue();
        if (avlTree != nullptr) 
        {
            std::vector<BorrowedBook> allBorrowedBooks = avlTree->getValues();
            for (int i = 0; i < allBorrowedBooks.size(); i++) 
            {
                borrowedBookTitles.push_back(allBorrowedBooks[i].getTitle());
            }
        }

    }

    return borrowedBookTitles;
}

// retrieve details of the borrower who borrowed the specified book
void BorrowedBook::retrieveBorrowerDetailsForBook(const HashTable<BorrowedBook>& borrowedBooks) {
    std::string bookTitle;

    //prompt the user for the book title
    std::cout << "Enter the title of the book to retrieve details: ";
    std::cin.clear(); // Clear any errors on the stream, if any.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore up to the newline
    std::getline(std::cin, bookTitle);

    //creating a dummy BorrowedBook with the given title
    BorrowedBook tempBorrowedBook(-1, bookTitle, "", "", ""); //default values for other attributes

    //search for the AVL tree using the title (hashed value)
    AVLTree<BorrowedBook>* tree = borrowedBooks.search(bookTitle);

    if (tree)
    {
        //search the AVL tree using the dummy borrowed book
        BorrowedBook* foundBorrowedBook = tree->search(tempBorrowedBook);

        //if the borrowed book is found display its details
        if (foundBorrowedBook)
        {
            std::cout << std::endl;
            std::cout << "-------------------------------------------\n";
            std::cout << "Book Title: " << foundBorrowedBook->getTitle() << std::endl;
            std::cout << "Borrower: " << foundBorrowedBook->getBorrower() << std::endl;
            std::cout << "Issue Date: " << foundBorrowedBook->getIssueDate() << std::endl;
            std::cout << "Due Date: " << foundBorrowedBook->getDueDate() << std::endl;
            return;
        }
    }

    std::cout << "Book titled '" << bookTitle << "' is not borrowed." << std::endl;
}

//implementations of operator overloading

//definitions for operator overloading
//comparison Operators:

bool operator<(const BorrowedBook& lhs, const BorrowedBook& rhs) {
    return lhs.getTitle() < rhs.getTitle();
}

bool operator>(const BorrowedBook& lhs, const BorrowedBook& rhs) {
    return lhs.getTitle() > rhs.getTitle();
}

bool operator==(const BorrowedBook& lhs, const BorrowedBook& rhs) {
    return lhs.getTitle() == rhs.getTitle();
}

bool operator!=(const BorrowedBook& lhs, const BorrowedBook& rhs) {
    return !(lhs == rhs);
}

bool operator<=(const BorrowedBook& lhs, const BorrowedBook& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const BorrowedBook& lhs, const BorrowedBook& rhs) {
    return !(lhs < rhs);
}

// Stream Operators:

std::ostream& operator<<(std::ostream& os, const BorrowedBook& book) {
    os << "ID: " << book.getId()
        << "\nTitle: " << book.getTitle()
        << "\nBorrowed by: " << book.getBorrower()
        << "\nIssue Date: " << book.getIssueDate()
        << "\nDue Date:" << book.getDueDate() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, BorrowedBook& book) {
    int id;
    std::string title, borrower, issue_date, due_date;

    std::cout << "Enter Book ID: ";
    is >> id;
    is.ignore();

    std::cout << "Enter Title: ";
    std::getline(is, title);

    std::cout << "Enter Borrower's Name: ";
    std::getline(is, borrower);

    std::cout << "Enter Issue Date: ";
    std::getline(is, issue_date);

    std::cout << "Enter Due Date: ";
    std::getline(is, due_date);

    book.setId(id);
    book.setTitle(title);
    book.setBorrower(borrower);
    book.setIssueDate(issue_date);
    book.setDueDate(due_date);

    return is;
}