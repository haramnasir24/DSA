// a function that recursively searches a value in an array of size n

#include <iostream>
using namespace std;

// returns index in array
int SearchValue(int *Array, int element, int index, int size)
{
    while (index < size)
    {
        if (Array[index] == element)
        {
            // base case
            return index;
        }
        else
        {
            // recursive call
            // index++;
            SearchValue(Array, element, ++index, size);
        }
    }
    return -1;
}

int main()
{
    int size;
    int element;
    int index = 0;
    cout << "Enter size of array: ";
    cin >> size;
    int *Array = new int[size];

    // populating the array
    for (int x = 0; x < size; x++)
    {
        cout << "Enter the array element: ";
        cin >> Array[x];
    }

    // printing the array
    cout << "The array is given as: [ ";
    for (int x = 0; x < size; x++)
    {
        cout << Array[x] << " ";
    }
    cout << "]" << endl;

    cout << "Enter the element to search in the array: ";
    cin >> element;

    if (SearchValue(Array, element, index, size) != -1)
    {
        cout << "Element is found at index " << SearchValue(Array, element, index, size) << endl;
    }

    else
    {
        cout << "Element does not exist!" << endl;
    }

    return 0;
}