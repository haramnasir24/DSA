#include <iostream>
using namespace std;

int a = 5, b = 10;
int *pa = &a; // pa and pb are pointer variables of type int.
int *pb = &b;

int **ppa = &pa; // ppa and ppb are called double pointers or pointers-to-pointers.
// // **ppa contains value of a and **ppb contains value of b
// // *ppa and *ppb contain values of pa and pb respectively or addresses of a and b
int **ppb = &pb;

// c)	Write code of a function that swaps values of the variables a and b using pointer-to-pointer variables ppa and ppb

void swap(int **ppa,int **ppb)
{
    // swapping double pointers here 
    int temp;
    temp= **ppa;
    **ppa= **ppb;
    **ppb= temp;
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
}

int main()
{
    cout << "BEFORE SWAP" << endl;
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
    cout << "AFTER SWAP" << endl;
    swap(&pa, &pb);
    return 0;
}
