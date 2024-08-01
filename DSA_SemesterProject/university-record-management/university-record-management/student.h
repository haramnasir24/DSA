// TEMPLATE FOR STUDENT DATA

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

#include "AVLTree.h"
#include "Hash_Table.h"

class Student;  // forward declaration of Student class

// operator overloading for comparison operators
bool operator<(const Student& lhs, const Student& rhs);
bool operator>(const Student& lhs, const Student& rhs);
bool operator<=(const Student& lhs, const Student& rhs);
bool operator>=(const Student& lhs, const Student& rhs);
bool operator==(const Student& lhs, const Student& rhs);
bool operator!=(const Student& lhs, const Student& rhs);

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Student& student);
// operator overloading for input stream operator
std::istream& operator>>(std::istream& is, Student& student);

class Student
{
private:
    int id;
    std::string name;
    int age;
    int grade;

public:
    //constructor declaration
    //parameterized constructor
    Student(int id, const std::string& name, int age, int grade);


    // Getter method declarations
    int getId() const;
    std::string getName() const;
    int getAge() const;
    int getGrade() const;

    // Setter method declarations
    void setId(int newId);
    void setName(const std::string& newName);
    void setAge(int newAge);
    void setGrade(int newGrade);

    //method declarations
    void print() const;
    static void retrieveAndPrintStudentDetails(const HashTable<Student>& studentTable);
    static void retrieveAndPrintStudentsByAge(const HashTable<Student>& studentTable);
    static void retrieveAndPrintStudentsByGrade(const HashTable<Student>& studentTable);
    static void printAgeFrequency(const HashTable<Student>& studentTable);
    static void promoteStudent(HashTable<Student>& studentTable);
    static void deleteStudentRecord(HashTable<Student>& studentTable, int studentId);

};

#endif // STUDENT_H
