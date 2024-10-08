// INSERTION SORT
// assume first element is always sorted
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

// function to implement insertion sort
void sort(int *array, int size)
{
    int n = size;
    for (int i = 1; i < n; i++) // runs n-1 times because we skip first element
    {
        int current = array[i];
        int j = i - 1;
        while (array[j] > current && j >= 0)
        {
            swap(array[j], array[j+1]); // array[j+1] == current
            j--;
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
    cout << "Time taken by insertion sort: " << time_taken << " ms" << endl;

    cout << "The sorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}