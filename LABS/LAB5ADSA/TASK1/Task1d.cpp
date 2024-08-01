// SORTING USING MERGE SORT

#include <iostream>
using namespace std;

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
    mergeSort(array, 0, (size - 1));

    cout << "The sorted array is given as: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}