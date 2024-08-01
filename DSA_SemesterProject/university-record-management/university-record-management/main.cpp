#include <iostream>
#include <vector>

#include "parser.h"
#include "student.h"
#include "book.h"
#include "borrowed_book.h"
#include "utilities.h"
#include "Hash_Table.h"
#include "AVLTree.h"


using namespace std;

int main()
{

    // load data from CSV files
    vector<Student> students = readStudentCSV("students.csv");
    vector<Book> books = readBookCSV("books.csv");

    // initialize hash tables
    HashTable<Student> studentTable(static_cast<int>(students.size()));
    HashTable<Book> bookTable(static_cast<int>(books.size()));
    //creating an empty hash table for borrowed books the same size as book inventory
    HashTable<BorrowedBook> borrowedBookTable(static_cast<int>(books.size()));  

    // populate hash tables
    populateStudentHashTable(studentTable, students);
    populateBookHashTable(bookTable, books);

    //flags to track changes in the hash tables
    bool studentDataChanged = false;
    bool bookDataChanged = false;
    bool borrowedBookDataChanged = false;

    int choice;
    do
    {
        cout << "\nMAIN MENU:" << endl;
        cout << "1. Student Management System" << endl;
        cout << "2. Library Management System" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        //to handle invalid user input
        if (!cin) //if the stream is in an error state (e.g., because the user didn't input a number)
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); //clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard invalid input
            continue; //jump to the next iteration of the loop
        }


        switch (choice)
        {
        case 1:
        {
            int studentChoice;
            do
            {
                cout << "\n\nSTUDENT MANAGEMENT SYSTEM:" << endl;
                cout << "1. Print Student Data" << endl;
                cout << "2. Print details of a particular student" << endl;
                cout << "3. Print details of students of a particular age" << endl;
                cout << "4. Print details of students of a particular grade levels" << endl;
                cout << "5. Print age frequency for any grade level" << endl;
                cout << "6. Promote student grade level" << endl;
                cout << "7. Delete student record" << endl;
                cout << "0. Go Back to Main Menu" << endl;
                cout << "\nEnter your choice: ";
                cin >> studentChoice;

                //to handle invalid user input
                if (!cin)
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                switch (studentChoice)
                {
                case 1:
                {
                    cout << "STUDENT DATA:" << endl;
                    studentTable.printTable();
                }
                break;
                case 2:
                {
                    Student::retrieveAndPrintStudentDetails(studentTable);
                }
                break;
                case 3:
                {
                    Student::retrieveAndPrintStudentsByAge(studentTable);
                }
                break;
                case 4:
                {
                    Student::retrieveAndPrintStudentsByGrade(studentTable);
                }
                break;
                case 5:
                {
                    Student::printAgeFrequency(studentTable);
                }
                break;
                case 6:
                {
                    Student::promoteStudent(studentTable);
                    studentDataChanged = true;
                }
                break;
                case 7:
                {
                    int studentId;
                    std::cout << "Enter the student ID to delete: ";
                    std::cin >> studentId;
                    Student::deleteStudentRecord(studentTable, studentId);
                    studentDataChanged = true;
                }
                break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (studentChoice != 0);
        }
        break;
        case 2:
        {
            int libraryChoice;
            do
            {
                cout << "\n\nLIBRARY MANAGEMENT SYSTEM:" << endl;
                cout << "1. Print Book Data" << endl;
                cout << "2. Check if a Book is Available" << endl;
                cout << "3. Print Available Books" << endl;
                cout << "4. Borrow a book" << endl;
                cout << "5. Return a borrowed book" << endl;
                cout << "6. Print information of borrowed books" << endl;
                cout << "7. Print borrower details for a book" << endl;
                cout << "8. Print all books written by the same author " << endl;
                cout << "9. Print all books written in the same year" << endl;
                cout << "0. Go Back to Main Menu" << endl;
                cout << "\nEnter your choice: ";
                cin >> libraryChoice;
                //to handle invalid user input
                if (!cin)
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                switch (libraryChoice)
                {
                case 1:
                {
                    cout << "BOOK DATA:" << endl;
                    bookTable.printTable();
                }
                break;
                case 2:
                {
                    string title;
                    cout << "Enter book title to check availability: ";
                    cin.ignore(); // Clear the newline left in the input buffer
                    getline(cin, title);
                    if (Book::isBookAvailable(bookTable, title))
                        cout << "The book is available!" << endl;
                    else
                        cout << "The book is not available." << endl;
                }
                break;
                case 3:
                {
                    Book::retrieveAndPrintAvailableBooks(bookTable);
                }
                break;
                case 4:
                {
                    BorrowedBook::borrowBook(bookTable, borrowedBookTable); 
                    bookDataChanged = true;
                    borrowedBookDataChanged = true;
                }
                break;
                case 5:
                {
                    BorrowedBook::returnBook(bookTable, borrowedBookTable); 
                    bookDataChanged = true;
                    borrowedBookDataChanged = true;
                }
                break;
                case 6:
                {
                    std::vector<std::string> borrowedBooksList = BorrowedBook::getBorrowedBooks(borrowedBookTable);
                    if (borrowedBooksList.empty()) 
                    {
                        std::cout << "No books have been borrowed.\n";
                    }
                    else 
                    {
                        std::cout << "\nBorrowed Books:\n";
                        for (int i = 0; i < borrowedBooksList.size(); i++) 
                        {
                            std::cout << i + 1 << ". " << borrowedBooksList[i] << "\n";
                        }
                    }
                }
                break;
                case 7:
                {
                    BorrowedBook::retrieveBorrowerDetailsForBook(borrowedBookTable);
                }
                break;
                case 8:
                {
                    Book::retrieveBooksByAuthor(bookTable);
                }
                break;
                case 9:
                {
                    Book::retrieveBooksByYear(bookTable);
                }
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (libraryChoice != 0);
        }
        break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    //before exiting the session write all hash tables into respective csv files with updated data
    //check if said hash table has had any changes by flags
    if (studentDataChanged) 
    {
        writeStudentCSV(studentTable,"students.csv");  
    }

    if (bookDataChanged) 
    {
        writeBookCSV(bookTable, "books.csv");  
    }

    if (borrowedBookDataChanged) 
    {
        writeBorrowedBookCSV( borrowedBookTable, "borrowed_books.csv");  
    }

    return 0;
}
