// SORTING USING SELECTION SORT

#include <iostream>
using namespace std;

// function to swap array elements
// passing pointer to the address
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to implement selection sort
void sort(int *array, int size)
{
    int n = size;
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            // comparisons
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        // data movements
        // pass by address
        swap(&array[i], &array[min_index]);
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter an element: ";
        cin >> array[i];
    }
    cout << endl;

    cout << "The unsorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // function call to sort
    sort(array, size);

    cout << "The sorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}