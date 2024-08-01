#include "student.h"

//definitions for class member methods
   // constructor for student instance
Student::Student(int id, const std::string& name, int age, int grade)
    : id(id), name(name), age(age), grade(grade) {}

// getters
int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
int Student::getGrade() const { return grade; }

// setters
void Student::setId(int newId) { id = newId; }
void Student::setName(const std::string& newName) { name = newName; }
void Student::setAge(int newAge) { age = newAge; }
void Student::setGrade(int newGrade) { grade = newGrade; }

// method to print out student details
void Student::print() const {
    std::cout << "ID: " << getId() << "\nName: " << getName() << "\nAge: " << getAge() << "\nGrade: " << getGrade() << std::endl;
}

//function to retrieve and print student details by name (assuming students have a unique name)
void Student::retrieveAndPrintStudentDetails(const HashTable<Student>& studentTable) {
    std::string studentName;

    //prompt the user for the student's name
    std::cout << "----------------------------------------------------\n";
    std::cout << "Enter the name of the student to retrieve details: ";
    std::cin.clear(); //clear any errors on the stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore up to the newline
    std::getline(std::cin, studentName);

    AVLTree<Student>* avlTree = studentTable.search(studentName);
    if (avlTree == nullptr) {
        std::cout << "\nStudent with name " << studentName << " not found." << std::endl;
        return;
    }

    //fetch students and print details
    std::vector<Student> students = avlTree->getValues();
    for (int i = 0; i < students.size(); ++i) {
        std::cout << "\nStudent details for " << studentName << ":" << std::endl;
        students[i].print();
        std::cout << std::endl;
    }
}

void Student::retrieveAndPrintStudentsByAge(const HashTable<Student>& studentTable) {
    int age;

    //prompt the user for age
    std::cout << "----------------------------------------------------\n";
    std::cout << "Enter the age of the students to retrieve details: ";
    std::cin >> age;

    // get all items from the hash table
    std::vector<HashTable<Student>::Item*> items = studentTable.getItems();

    // iterate through the hash table to find the students of a particular age
    for (int i = 0; i < items.size(); i++)
    {
        AVLTree<Student>* avlTree = items[i]->getHashValue();

        if (avlTree != nullptr)
        {
            // get all students from the AVL tree
            std::vector<Student> students = avlTree->getValues();

            // loop over the students and print the ones that match the given age
            for (int j = 0; j < students.size(); j++)
            {
                if (students[j].getAge() == age)
                {
                    std::cout << students[j] << std::endl;
                }
            }
        }
    }
}

void Student::retrieveAndPrintStudentsByGrade(const HashTable<Student>& studentTable) {
    int grade;

    //prompt the user for grade
    std::cout << "----------------------------------------------------\n";
    std::cout << "Enter the grade of the students to retrieve details: ";
    std::cin >> grade;
    std::vector<HashTable<Student>::Item*> items = studentTable.getItems();
    for (int i = 0; i < items.size(); ++i) {
        AVLTree<Student>* avlTree = items[i]->getHashValue();
        if (avlTree != nullptr) 
        {
            std::vector<Student> studentsInTree = avlTree->getValues();
            for (int j = 0; j < studentsInTree.size(); ++j) 
            {
                if (studentsInTree[j].getGrade() == grade) 
                {
                    std::cout << "\nStudent details for Grade " << grade << ":" << std::endl;
                    studentsInTree[j].print();
                    std::cout << std::endl;
                }
            }
        }
    }
}

void Student::printAgeFrequency(const HashTable<Student>& studentTable) {
    //create an array to store frequency for ages from 13 to 19.
    int ageFrequencies[7] = { 0 }; //initialize all to zero

    //prompt user for grade information
    int grade;
    std::cout << "Enter the grade level: ";
    std::cin >> grade;
    while (std::cin.fail() || grade < 9 || grade > 12) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid grade level (1-12): ";
        std::cin >> grade;
    }

    //get all students from the hash table
    std::vector<Student> students = studentTable.getAllValues();

    //iterate through each student and count the frequency for the age if they are in the specified grade
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getGrade() == grade && students[i].getAge() >= 13 && students[i].getAge() <= 19) {
            ageFrequencies[students[i].getAge() - 13]++;
        }
    }

    //print out the frequencies for each age from 13 to 19
    std::cout << "----------------------------------------\n";
    std::cout << "Age frequency for grade " << grade << ":\n";
    for (int i = 0; i < 7; ++i) {
        std::cout << i + 13 << ": " << ageFrequencies[i] << "\n";
    }
}

void Student::promoteStudent(HashTable<Student>& studentTable) {
    int studentId;

    std::cout << "Enter the student ID to promote: ";
    std::cin >> studentId;

    std::vector<Student> allStudents = studentTable.getAllValues();
    bool found = false;

    //loop through all students to find the matching ID
    for (int i = 0; i < allStudents.size(); i++) {
        if (allStudents[i].getId() == studentId) {
            int currentGrade = allStudents[i].getGrade();
            std::string studentName = allStudents[i].getName();  //retrieve the student's name

            allStudents[i].setGrade(currentGrade + 1);

            if (allStudents[i].getGrade() > 12) {
                std::cout << "Student " << studentName << " with ID " << studentId << " has graduated." << std::endl;
                deleteStudentRecord(studentTable, studentId);
            }
            else {
                std::cout << "Student " << studentName << " with ID " << studentId << " has been promoted to grade " << allStudents[i].getGrade() << "." << std::endl;
            }
            found = true;
            break;  // exit the loop once the student is found and promoted or deleted
        }
    }

    if (!found) {
        std::cout << "Student with ID " << studentId << " not found in the system." << std::endl;
    }
}

void Student::deleteStudentRecord(HashTable<Student>& studentTable, int studentId) {
    std::vector<Student> allStudents = studentTable.getAllValues();
    bool found = false;

    // Loop through all students to find the matching ID
    for (int i = 0; i < allStudents.size(); i++) {
        if (allStudents[i].getId() == studentId) {
            std::string studentName = allStudents[i].getName();  //retrieve the student's name
            studentTable.remove(std::to_string(studentId), allStudents[i]);
            std::cout << "Student " << studentName << " with ID " << studentId << " has been deleted." << std::endl;
            found = true;
            break;  // exit the loop once the student is found and deleted
        }
    }

    if (!found) {
        std::cout << "Student with ID " << studentId << " not found in the system." << std::endl;
    }
}


// operator overloading for comparison operators
bool operator<(const Student& lhs, const Student& rhs) {
    return lhs.getName() < rhs.getName();
}

bool operator>(const Student& lhs, const Student& rhs) {
    return lhs.getName() > rhs.getName();
}

bool operator<=(const Student& lhs, const Student& rhs) {
    return lhs.getName() <= rhs.getName();
}

bool operator>=(const Student& lhs, const Student& rhs) {
    return lhs.getName() >= rhs.getName();
}

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.getName() == rhs.getName();
}

bool operator!=(const Student& lhs, const Student& rhs) {
    return lhs.getName() != rhs.getName();
}

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "\nStudent ID: " << student.getId() << "\nName: " << student.getName() << "\nAge: " << student.getAge() << "\nGrade: " << student.getGrade() << std::endl;
    return os;
}

// operator overloading for input stream operator
std::istream& operator>>(std::istream& is, Student& student) {
    int id;
    std::string name;
    int age;
    int grade;

    std::cout << "Enter Student ID: ";
    is >> id;
    student.setId(id);

    std::cout << "Enter Student Name: ";
    is.ignore(); // clear the newline from the buffer
    std::getline(is, name);
    student.setName(name);

    std::cout << "Enter Student Age: ";
    is >> age;
    student.setAge(age);

    std::cout << "Enter Student Grade: ";
    is >> grade;
    student.setGrade(grade);

    return is;
}