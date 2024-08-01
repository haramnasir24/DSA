#include <iostream>
using namespace std;

int main(){
    // initialize a dynamic array using an initializer list 
    int *array{ new int[5]{ 10, 7, 15, 3, 11 } };

    // printing the array
    for (int x = 0; x < 5; x++)
    {
        cout << array[x] << " ";
    }


    return 0;
}


