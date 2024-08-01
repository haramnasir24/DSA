// Suppose you have an array-based list of size n.
// Implement a function takes a position number pos as input from the user,
// and returns the value stored at that position

// DYNAMIC ARRAY

// DYNAMIC ARRAY

#include <iostream>
using namespace std;

class Array
{
    int n;
    int *arr;

public:
    void PopulateAndPrintArray();
    int ElementAtPosition(int);
};

void Array::PopulateAndPrintArray()
{

    // taking user input
    cout << "Enter the value of variable n: ";
    cin >> n;

    // creating a dynamically allocated array
    // n is size of array
    arr= new int[n];
    cout << "Enter the items to be stored in the array." << endl;

    // populating the array
    for (int x = 0; x < n; x++)
    {
        cout << "Enter the array element: ";
        cin >> arr[x];
    }

    cout << "The array has been populated." << endl;

    // printing the array
    cout << "The array is given as: ";
    for (int x = 0; x < n; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
}

int Array::ElementAtPosition(int pos)
{
    int index;
    index = pos - 1;
    if (pos > 0 && pos < n + 1)
    {
        return arr[index];
    }
    else
    {
        return -1;
    }
}

int main()
{
    Array A;
    A.PopulateAndPrintArray();
    int pos;

    cout << "Enter a position: ";
    cin >> pos;

    if (A.ElementAtPosition(pos) != -1)
    {
        cout << "The element at position " << pos << " in the array is: " << A.ElementAtPosition(pos) << endl;
    }

    else
    {
        cout << "Invalid position." << endl;
    }

    return 0;
}