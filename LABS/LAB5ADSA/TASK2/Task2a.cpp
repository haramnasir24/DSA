// compare the running time of algorithms

#include <iostream>
#include <random>
#include <vector>
#include <chrono>
using namespace std;

// function to create randomized arrays
int *generateRandomArray(int size)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 1000);

    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = distribution(gen);
    }
    return arr;
}

// swapping - helper function
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// SELECTION SORT
void selectionSort(int *array, int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(&array[i], &array[min_index]);
    }
}

// BUBBLE SORT
void bubbleSort(int *array, int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

// SHORT BUBBLE SORT
void shortBubbleSort(int *array, int size)
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
                swap(&array[j], &array[j + 1]);
                isSwap = true;
            }
        }
        if (isSwap == false)
        {
            return;
        }
    }
}

// MERGE SORT
void merge(int *array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temporary arrays
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    // populating arrays
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        arr2[j] = array[mid + 1 + j];
    }

    int i = 0; // starting index of left subarray
    int j = 0; // starting index of right subarray
    int k = left; // starting index of merged array, this step also copies the merged array to the original array

    // sorting and merging
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            array[k] = arr1[i];
            i++;
        }
        else
        {
            array[k] = arr2[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements
    while (i < n1)
    {
        array[k] = arr1[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        array[k] = arr2[j];
        k++;
        j++;
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}


int main()
{
    int sizes[] = {100, 1000, 5000};

    for (int size : sizes)
    {
        int *randomArray = generateRandomArray(size);

        // Record the start time
        auto start = chrono::high_resolution_clock::now();

        // function call
        selectionSort(randomArray, size);

        // Record the end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate the elapsed time in milliseconds
        double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Time taken by selection sort: " << time_taken << " ms" << endl;
        delete[] randomArray;
    }

    for (int size : sizes)
    {
        int *randomArray = generateRandomArray(size);

        // Record the start time
        auto start = chrono::high_resolution_clock::now();

        // function call
        bubbleSort(randomArray, size);

        // Record the end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate the elapsed time in milliseconds
        double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Time taken by bubble sort: " << time_taken << " ms" << endl;
        delete[] randomArray;
    }

    for (int size : sizes)
    {
        int *randomArray = generateRandomArray(size);

        // Record the start time
        auto start = chrono::high_resolution_clock::now();

        // function call
        shortBubbleSort(randomArray, size);

        // Record the end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate the elapsed time in milliseconds
        double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Time taken by short bubble sort: " << time_taken << " ms" << endl;
        delete[] randomArray;
    }

    for (int size : sizes)
    {
        int *randomArray = generateRandomArray(size);

        // Record the start time
        auto start = chrono::high_resolution_clock::now();

        // function call
        mergeSort(randomArray,0, size-1);

        // Record the end time
        auto end = chrono::high_resolution_clock::now();

        // Calculate the elapsed time in milliseconds
        double time_taken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Time taken by merge sort: " << time_taken << " ms" << endl;
        delete[] randomArray;
    }

    return 0;
}