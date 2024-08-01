#include <iostream>
using namespace std;

int a = 5, b = 10;
int *pa = &a; // pa and pb are pointer variables of type int.
int *pb = &b;

int **ppa = &pa; // ppa and ppb are called double pointers or pointers-to-pointers.
// // **ppa contains value of a and **ppb contains value of b
// // *ppa and *ppb contain values of pa and pb respectively or addresses of a and b
int **ppb = &pb;

// b)	Write code of a function that swaps values of pointer variables pa and pb.
// Input to the function should be the address of both the pointer variables.

void swap(int **ppa,int **ppb)
{
    // swapping addresses here 
    // temp stores address 
    int *temp;
    temp = *ppa;
    *ppa= *ppb;
    *ppb= temp;
    cout << "value of pa: " << pa << endl;
    cout << "value of pb: " << pb << endl;
}

int main()
{
    cout << "BEFORE SWAP" << endl;
    cout << "value of pa: " << pa << endl;
    cout << "value of pa: " << pb << endl;
    cout << "AFTER SWAP" << endl;
    swap(&pa,&pb);
    return 0;
}
