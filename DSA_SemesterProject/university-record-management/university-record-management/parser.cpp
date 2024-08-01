#include "parser.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// parser function to read data from students
std::vector<Student> readStudentCSV(const string& filename)
{
	// vector of students data
	std::vector<Student> students;
	ifstream file(filename);

	if (!file.is_open())
	{
		// throw runtime_error("Could not open file");
		std::cout << "Could not open file.\n";
	}
	string line, word;

	// skip the header
	if (file.good())
	{
		getline(file, line);
	}

	while (getline(file, line))
	{
		// creates a stream of lines
		istringstream s(line);

		// vector to store individual words of a line
		vector<string> words;

		while (getline(s, word, ','))
		{
			// populating the vector
			words.push_back(word);
		}

		if (words.size() < 4) // because the student csv file is expected to have at least 4 columns
			continue;

		int id = std::stoi(words[0]);
		string name = words[1];
		int age = std::stoi(words[2]);
		int grade = std::stoi(words[3]);
		students.emplace_back(id, name, age, grade);
	}

	file.close();
	return students;
}

// parser function to read data from books
std::vector<Book> readBookCSV(const string& filename)
{
	// vector that contains books data
	vector<Book> books;
	ifstream file(filename);

	if (!file.is_open())
	{
		// throw runtime_error("Could not open file");
		std::cout << "Could not open file.\n";
	}

	string line, word;

	// skip the header
	if (file.good())
	{
		getline(file, line);
	}

	while (getline(file, line))
	{
		istringstream s(line);
		vector<string> words;

		while (getline(s, word, ','))
		{
			words.push_back(word);
		}

		if (words.size() < 6)
			continue;

		int id = std::stoi(words[0]);
		string title = words[1];
		string author = words[2];
		int publishing_year = stoi(words[3]);
		std::string value = words[4];
		std::transform(value.begin(), value.end(), value.begin(), ::tolower); //transform the whole word into lowercase
		bool isAvailable = (value == "true");
		int quantity = stoi(words[5]);
		books.emplace_back(id, title, author, publishing_year, isAvailable, quantity);
	}

	file.close();
	return books;
}

// parser function to read data from borrowed books
vector<BorrowedBook> readBorrowedCSV(const string& filename)
{
	vector<BorrowedBook> borrowedBooks;
	ifstream file(filename);

	if (!file.is_open())
	{
		// throw runtime_error("Could not open file");
		std::cout << "Could not open file.\n";
	}
	string line, word;

	// skip the header
	if (file.good())
	{
		getline(file, line);
	}

	while (getline(file, line))
	{
		istringstream s(line);
		vector<string> words;

		while (std::getline(s, word, ','))
		{
			words.push_back(word);
		}

		if (words.size() < 5)
			continue;

		int id = std::stoi(words[0]);
		string title = words[1];
		string borrower = words[2];
		string issue_date = (words[3]);
		string due_date = (words[4]);
		borrowedBooks.emplace_back(id, title, borrower, issue_date, due_date);
	}

	file.close();
	return borrowedBooks;
}

//write student data from hash table to csv file
void writeStudentCSV(const HashTable<Student>& studentTable, const std::string& filename) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cout << "Could not open file for writing.\n";
		return;
	}

	// Write header
	file << "ID,Name,Age,Grade\n";

	std::vector<Student> students = studentTable.getAllValues();
	for (const Student& student : students) 
	{
		file << student.getId() << ","
			<< student.getName() << ","
			<< student.getAge() << ","
			<< student.getGrade() << "\n";
	}

	file.close();
}

//write book data from hash table to csv file
void writeBookCSV(const HashTable<Book>& bookTable, const std::string& filename) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cout << "Could not open file for writing.\n";
		return;
	}

	//write header
	file << "ID,Title,Author,Publishing Year,Availability,Quantity\n";

	std::vector<Book> books = bookTable.getAllValues();
	for (const Book& book : books)
	{
		file << book.getId() << ","
			<< book.getTitle() << ","
			<< book.getAuthor() << ","
			<< book.getYear() << ","
			<< (book.getAvailability() ? "true" : "false") << ","
			<< book.getQuantity() << "\n";
	}

	file.close();
}

//write borrowed book data from hash table to csv file
void writeBorrowedBookCSV(const HashTable<BorrowedBook>& borrowedBookTable, const std::string& filename) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cout << "Could not open file for writing.\n";
		return;
	}

	//write header
	file << "ID,Title,Borrower,Issue Date,Due Date\n";

	std::vector<BorrowedBook> borrowedBooks = borrowedBookTable.getAllValues();
	for (const BorrowedBook& borrowed : borrowedBooks)
	{
		file << borrowed.getId() << ","
			<< borrowed.getTitle() << ","
			<< borrowed.getBorrower() << ","
			<< borrowed.getIssueDate() << ","
			<< borrowed.getDueDate() << "\n";
	}

	file.close();
}
