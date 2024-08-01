// REGULAR OR STATIC ARRAY

#include <iostream>
using namespace std;

int main()
{
    int x;
    // creating a static array
    const int size = 5;
    int arr[size];
    // populating the array
    for (int x = 0; x < size; x++)
    {
        cout << "Enter the array element: ";
        cin >> arr[x];
    }

    cout << "The array has been populated." << endl;

    // printing the array
    cout << "The array is given as: " << endl;
    for (int x = 0; x < size; x++)
    {
        cout << arr[x] << " ";
    }

    return 0;
}