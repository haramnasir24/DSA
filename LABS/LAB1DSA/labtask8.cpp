#include <iostream>
using namespace std;

class ArrayList
{
    // When used inside a class, static const is used to declare a class-level constant, which is shared among all instances of the class.
    int static const MaxSize = 8;
    int length = 0; // empty array
    int array[MaxSize];

    // Member functions

public:
    // checks if array is empty
    bool isEmpty()
    {
        return length == 0;
    }

    // checks if array is full
    bool isFull()
    {
        return length == MaxSize;
    }

    // inserts element at end of array
    void InsertAtEnd(int value)
    {
        if (!isFull())
        {
            array[length] = value;
            length++;
        }
        else
        {
            cout << "Array is full!" << endl;
        }
    }

    // helper function
    void MakeRoom(int position) // shifts elements to right to insert element at a particular position
    {

        for (int i = length; i >= position; i--)
        {
            array[i] = array[i-1];
        }
    }

    // inserts element at a particular position
    void InsertAtPosition(int value, int position)
    {
        if (!isFull())
        {
            if (position >=1 && position <= length)
            {
                MakeRoom(position);
                array[position - 1] = value;
                length++;
            }
            else if (position == length + 1) // insertion at end no need to make room
            {
                array[length] = value;
                length++;
            }
            else
            {
                cout << "Invalid position, can't insert." << endl;
            }
        }
        else
        {
            cout << "Array is full!" << endl;
        }
    }

    // searches an element in the array and returns its position
    int Search(int value)
    {
        if (!isEmpty())
        {
            for (int i = 0; i < length; i++)
            {
                if (array[i] == value)
                {
                    return (i + 1); // returns position of searched element
                }
            }
        }
        else
        {
            cout << "Array is empty, nothing to search." << endl;
        }
        return -1; // for element that is not in the list
    }

    // helper function
    void FillRoom(int value) // deletes element and shifts remaining elements to the left
    {
        // Search(value); returns position
        int index = (Search(value) - 1);
        for (int i = index; i < (length - 1); i++)
        {
            array[i] = array[i + 1];
        }
    }

    // deletes an element from the array
    void Delete(int value)
    {
        if (!isEmpty())
        {
            if ((Search(value) == length)) // deletion at end no need to fill
            {
                length--;
            }
            else if(((Search(value)>=1) && (Search(value)<length))) // deletion anywhere else
            {
                FillRoom(value);
                length--;
            }
            else{
                cout << "Element to be deleted is not in the list." << endl;
            }
        }
        else
        {
            cout << "Array is empty, nothing to delete." << endl;
        }
    }

    // displays the list
    void PrintList()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < length; i++)
            {
                cout << array[i] << " ";
            }
        }
        else
        {
            cout << "Array is empty!" << endl;
        }
    }
};

int main()
{
    ArrayList A1;
    // Insert 5 int values in the list
    A1.InsertAtPosition(10, 1);
    A1.InsertAtPosition(20, 3);
    A1.InsertAtPosition(30, 2);
    A1.InsertAtPosition(40, 4);
    A1.InsertAtEnd(50);

    A1.PrintList(); 
    cout << endl;

    // A1.InsertAtPosition(0, 44);

    // A1.InsertAtPosition(2, 55);

    // A1.InsertAtPosition(10, 66);

    A1.PrintList();
    cout << endl;

    cout << A1.Search(30) << endl;
    A1.Delete(50);
    A1.PrintList();

    return 0;
}


