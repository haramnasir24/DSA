// SORTING USING QUICK SORT

#include <iostream>
#include <chrono>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// returns pivot index
int partition(int *array, int left, int right, int &partitionCount)
{
    // assign last element as the pivot
    int pivot = right;

    // keeps track of the last element that is smaller than pivot
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (array[j] < array[pivot])
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    // places pivot in the right position
    swap(array[i + 1], array[pivot]);
    partitionCount++;
    return i + 1;
}

void QuickSort(int *array, int left, int right, int &partitionCount)
{
    if (left < right)
    {
        // index of pivot element, partition around pivot element
        int pivot = partition(array, left, right, partitionCount);

        QuickSort(array, left, pivot - 1, partitionCount);
        QuickSort(array, pivot + 1, right, partitionCount);
    }
}

int main()
{
    int size;
    int partitionCount = 0;
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
    QuickSort(array, 0, (size - 1), partitionCount);

    // Record the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Time taken by quick sort: " << time_taken << " ms" << endl;

    cout << "The sorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Number of partitions: " << partitionCount << endl;

    delete[] array;

    return 0;
}