#ifndef PARSER_H
#define PARSER_H


#include <string>
#include <vector>
#include "student.h"
#include "book.h"
#include "borrowed_book.h"

//declarations for reading data from CSV files

std::vector<Student> readStudentCSV(const std::string& filename);
std::vector<Book> readBookCSV(const std::string& filename);
std::vector<BorrowedBook> readBorrowedCSV(const std::string& filename);

//declarations for writing data to CSV files

void writeStudentCSV(const HashTable<Student>& studentTable, const std::string& filename);
void writeBookCSV(const HashTable<Book>& bookTable, const std::string& filename);
void writeBorrowedBookCSV(const HashTable<BorrowedBook>& borrowedBookTable, const std::string& filename);

#endif //PARSER_H
