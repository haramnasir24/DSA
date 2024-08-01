#include <iostream>
using namespace std;

int a = 5, b = 10;
int *pa = &a; // pa and pb are pointer variables of type int.
int *pb = &b;

int **ppa = &pa; // ppa and ppb are called double pointers or pointers-to-pointers.
// ppa contains address of a and ppb contains address of b
int **ppb = &pb;

// a)	Write code of a function that swaps values of variables a and b.
// Input to the function should be the address of both the variables.

void swap(int *pa,int *pb)
{
    int temp;
    temp = *pa;
    *pa= *pb;
    *pb= temp;
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
}

int main()
{
    // swap(pa, pb); or
    swap(&a,&b);
    return 0;
}
