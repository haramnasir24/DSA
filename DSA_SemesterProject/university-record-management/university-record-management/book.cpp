#include "book.h"

//class member methods definitions
// constructor for book instance
Book::Book(int id, const std::string& title, const std::string& author, int year, bool isAvailable, int quantity)
    : id(id), title(title), author(author), publishing_year(year), isAvailable(isAvailable), quantity(quantity) {}

// getter functions
int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return publishing_year; }
bool Book::getAvailability() const { return isAvailable; }
int Book::getQuantity() const { return quantity; }

// setter (helper) functions
void Book::setQuantity(int newQuantity) { this->quantity = newQuantity; }
void Book::setAvailability(bool availability) { this->isAvailable = availability; }
void Book::setId(int newId) { this->id = newId; }
void Book::setYear(int newYear) { this->publishing_year = newYear; }
void Book::setTitle(std::string& newTitle) { this->title = newTitle; }
void Book::setAuthor(std::string& newAuthor) { this->author = newAuthor; }

// for printing book details
void Book::print() const
{
    std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " << publishing_year << "\nBook availability status: " << boolalpha << isAvailable << "\nAuthor: "
        << author << "\nQuantity: " << quantity << std::endl;
}

// function to switch between availability status of a book
void Book::updateAvailabilityStatus()
{
    if (getQuantity() > 0)
    {
        setAvailability(true);
    }
    else
    {
        setAvailability(false);
    }
}

// checks if a book is available or not
   //logarithmic search for avl
bool Book::isBookAvailable(const HashTable<Book>& bookTable, const std::string& title)
{
    //creating a dummy book with the given title
    Book tempBook(-1, title, "", -1, false, 0); //default values for other attributes

    // Search for the AVL tree using the title (hashed value)
    AVLTree<Book>* tree = bookTable.search(title);

    if (tree)
    {
        //search the AVL tree using the dummy book
        //AVL tree search function expects a book object
        Book* foundBook = tree->search(tempBook);

        //if the book is found return its availability
        if (foundBook)
        {
            return foundBook->getAvailability();
        }
    }

    return false; // Book not found or not available
}


// retrieve books that are set as available 
void Book::retrieveAndPrintAvailableBooks(HashTable<Book>& bookTable) 
{
    cout << "Available Books:" << endl;

    // get all items from the hash table
    std::vector<HashTable<Book>::Item*> items = bookTable.getItems();

    // iterate through the hash table to find the available books
    for (int i = 0; i < items.size(); i++)
    {
        AVLTree<Book>* avlTree = items[i]->getHashValue();

        if (avlTree != nullptr)
        {
            // get all books from the AVL tree
            std::vector<Book> books = avlTree->getValues();

            // loop over the books and print the ones that are available
            for (int j = 0; j < books.size(); j++)
            {
                if (books[j].getAvailability())
                {
                    std::cout << books[j] << endl;
                }
            }
        }
    }
}

void Book::retrieveBooksByAuthor(const HashTable<Book>& bookTable) {
    std::string author;
    std::cout << "Enter the name of the author: ";
    std::cin.ignore();  //clear any newline left in the buffer
    std::getline(std::cin, author);

    std::vector<Book> booksByAuthor;  //to store the books by the specified author

    //assuming you have getAllValues function implemented as discussed before
    std::vector<Book> allBooks = bookTable.getAllValues();

    //loop through all books and check if the author matches
    for (int i = 0; i < allBooks.size(); i++) {
        if (allBooks[i].getAuthor() == author) {
            booksByAuthor.push_back(allBooks[i]);
        }
    }

    if (booksByAuthor.empty()) {
        std::cout << "\nNo books found by the author " << author << ".\n";
    }
    else {
        std::cout << "---------------------------------------------\n";
        std::cout << "\nBooks by " << author << " in our inventory:\n";
        for (int i = 0; i < booksByAuthor.size(); i++) {
            std::cout << booksByAuthor[i].getTitle() << "\n";  
        }
    }
}

void Book::retrieveBooksByYear(const HashTable<Book>& bookTable) {
    int year;
    std::cout << "Enter the year you want to search for: ";
    std::cin >> year;

    std::vector<Book> allBooks = bookTable.getAllValues();
    std::vector<Book> booksFromYear;  //to store the books published in the given year

    //loop through all books to check if the publishing year matches
    for (int i = 0; i < allBooks.size(); i++) {
        if (allBooks[i].getYear() == year) {
            booksFromYear.push_back(allBooks[i]);
        }
    }

    if (booksFromYear.empty()) {
        std::cout << "No books found that were published in the year " << year << ".\n";
    }
    else {
        std::cout << "----------------------------------\n";
        std::cout << "Books published in " << year << ":\n";
        for (int i = 0; i < booksFromYear.size(); i++) {
            std::cout << booksFromYear[i].getTitle() << " by " << booksFromYear[i].getAuthor() << "\n";  // Assuming Book has getTitle and getAuthor functions
        }
    }
}

// operator overloading for comparison operators
bool operator<(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() < rhs.getTitle();
}

bool operator>(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() > rhs.getTitle();
}

bool operator<=(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() <= rhs.getTitle();
}

bool operator>=(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() >= rhs.getTitle();
}

bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() == rhs.getTitle();
}

bool operator!=(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() != rhs.getTitle();
}

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "\nBook ID: " << book.getId() << "\nTitle: " << book.getTitle() << "\nPublishing Year: " << book.getYear()
        << "\nBook availability status: " << std::boolalpha << book.getAvailability() << "\nAuthor: " << book.getAuthor()
        << "\nQuantity: " << book.getQuantity() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
    int id;
    std::string title;
    std::string author;
    int year;
    bool availability;
    int quantity;

    //read data from input stream
    std::cout << "Enter Book ID: ";
    is >> id;
    book.setId(id);

    std::cout << "Enter Title: ";
    is.ignore(); //ignore newline character from previous input
    std::getline(is, title);
    book.setTitle(title);

    std::cout << "Enter Publishing Year: ";
    is >> year;
    book.setYear(year);

    std::cout << "Enter Book availability status (true/false): ";
    is >> availability;
    book.setAvailability(availability);

    std::cout << "Enter Author: ";
    is.ignore(); //ignore newline character from previous input
    std::getline(is, author);
    book.setAuthor(author);

    std::cout << "Enter Quantity: ";
    is >> quantity;
    book.setQuantity(quantity);

    return is;
}