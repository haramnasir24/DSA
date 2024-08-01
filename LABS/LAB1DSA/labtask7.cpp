// deleting the dynamically allocated array using delete[]

#include <iostream>
using namespace std;

int main()
{
    int x;
    int n;

    // taking user input
    cout << "Enter the value of variable n: ";
    cin >> n;

    // creating a dynamically allocated array
    // n is size of array
    int *arr = new int[n];
    cout << "Enter the n number of items to be stored in the array." << endl;

    // populating the array
    for (int x = 0; x < n; x++)
    {
        cout << "Enter the array element: ";
        cin >> arr[x];
    }

    cout << "The array has been populated." << endl;

    // printing the array
    cout << "The array is given as: " << endl;
    for (int x = 0; x < n; x++)
    {
        cout << arr[x] << " ";
    }

    cout << endl;

    // deleting the array
    delete[] arr;

    cout << "The array having" << " " <<n << " " << "elements has been deleted." << endl;
    
    return 0;
}