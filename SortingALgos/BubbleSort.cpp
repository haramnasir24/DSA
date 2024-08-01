// SORTING USING BUBBLE SORT
// highest number bubbles to the right with each iteration

#include <iostream>
#include <chrono>
using namespace std;

// function to swap array elements
// passing pointer to the address
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to implement bubble sort
void sort(int *array, int size)
{
    int n = size;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            // comparisons
            if (array[j] > array[j + 1])
            {
                // data movements
                swap(&array[j], &array[j + 1]);
            }
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

        // Record the start time
    auto start = chrono::high_resolution_clock::now();

    // function call to sort
    sort(array, size);

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Time taken by bubble sort: " << time_taken << " ms" << endl;


    cout << "The sorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}