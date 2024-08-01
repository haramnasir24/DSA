#include <iostream>
using namespace std;


void swap(int *ptra, int *ptrb ){
    int temp;
    temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;
}

int main()
{
    int a, b;
    cout << "Enter numbers: " << endl;
    cin >> a;
    cin >> b;
    swap(&a, &b);
    cout << "After swap" << endl;
    cout << "a: " << a << " b: " << b << endl;
    return 0;
}