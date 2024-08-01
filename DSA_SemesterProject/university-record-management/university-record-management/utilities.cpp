#include "utilities.h"
#include "parser.h"
#include <vector>

void populateBookHashTable(HashTable<Book>& bookTable, const vector<Book>& books)
{
    for (int i = 0; i < books.size(); i++)
    {
        bookTable.insert(books[i].getTitle(), books[i]);
    }
}

void populateStudentHashTable(HashTable<Student>& studentTable, const vector<Student>& students)
{
    for (int i = 0; i < students.size(); i++)
    {
        studentTable.insert(students[i].getName(), students[i]);
    }
}

std::string getCurrentDate() {
    //get the current time
    auto now = std::chrono::system_clock::now();

    //convert it to a time_t (a type for representing time) object
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    //convert it to a struct tm (time structure)
    std::tm now_tm;
    //localtime_s(&now_tm, &now_time);
    now_tm = *std::localtime(&now_time);
    //prepare a string stream
    std::ostringstream date_stream;

    //write the date into the string stream in the format YYYY-MM-DD
    date_stream << (now_tm.tm_year + 1900) << '-' << std::setfill('0') << std::setw(2) << (now_tm.tm_mon + 1) << '-' << std::setfill('0') << std::setw(2) << now_tm.tm_mday;

    //return the resulting string
    return date_stream.str();
}

std::string getTwoWeeksLaterDate()
{
    //get the current time
    auto now = std::chrono::system_clock::now();

    //add two weeks (represented as days) to the current time
    auto due = now + std::chrono::hours(24 * 14); // 24 hours/day * 14 days

    //convert it to a time_t object
    std::time_t due_time = std::chrono::system_clock::to_time_t(due);

    //convert it to a struct tm
    std::tm due_tm;
    //localtime_s(&due_tm, &due_time);
    due_tm = *std::localtime(&due_time);

    //prepare a string stream
    std::ostringstream date_stream;

    //write the date into the string stream in the format YYYY-MM-DD
    date_stream << (due_tm.tm_year + 1900) << '-' << std::setfill('0') << std::setw(2) << (due_tm.tm_mon + 1) << '-' << std::setfill('0') << std::setw(2) << due_tm.tm_mday;

    //return the resulting string
    return date_stream.str();
}

