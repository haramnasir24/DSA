// SORTING USING SHORT BUBBLE SORT
// optimized bubble sort

/* The key difference between Short Bubble Sort and the regular Bubble Sort is that
Short Bubble Sort has an extra optimization that checks whether any swaps were made during a pass.
If no swaps were made during a pass, it means the array is already sorted,
and the algorithm terminates early. */

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

// function to implement short bubble sort
void sort(int *array, int size)
{
    int n = size;
    // flag
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // comparisons
            if (array[j] > array[j + 1])
            {
                // data movements
                swap(array[j], array[j + 1]);
                isSwap = true;
            }
        }
        if (isSwap == false)
        {
            return;
        }
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