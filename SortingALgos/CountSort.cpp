// COUNT SORT
// linear time algorithm O(n)
// non comparison sorting
// uses three additional arrays

#include <iostream>
#include <chrono>
using namespace std;

// function to implement count sort
void CountSort(int *array, int size)
{
    int n = size;

    // store max element in k
    int k = array[0];

    for (int i = 1; i < n; i++)
    {
        if (array[i] > k)
        {
            k = array[i];
        }
    }

    // create count array (indexes 0 to k)
    // it contains count of every element at its index
    int *Count = new int[k + 1];

    // Initialize all elements to zero
    for (int i = 0; i <= k; i++)
    {
        Count[i] = 0;
    }

    // populating the count array
    for (int i = 0; i < n; i++)
    {
        Count[array[i]]++;
    }

    // modifying the count array
    for (int i = 1; i <= k; i++)
    {
        Count[i] += Count[i - 1];
    }

    // output array
    int *Output = new int[n];

    // traversing the original unsorted array and putting in output array
    for (int i = n - 1; i >= 0; i--)
    {
        Output[--Count[array[i]]] = array[i];
    }

    // copy output array to original array
    for (int i = 0; i < n; i++)
    {
        array[i] = Output[i];
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
    CountSort(array, size);

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Time taken by count sort: " << time_taken << " ms" << endl;

    cout << "The sorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}