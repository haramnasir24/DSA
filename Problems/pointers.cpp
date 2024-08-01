#include <iostream>
using namespace std;
int main()
{
    int size;
    int *array = new int[size];
    cout << "Enter size: " << endl;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: ";
        cin >> array[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }

    cout << "shhsdh" << endl;

    // cout << array;
    cout << array;

    return 0;
}