// recursive function to compute the Fibonacci of a non-negative integer position n

#include <iostream>
using namespace std;

int ComputeFibonacci(int pos)
{
    // base cases
    if (pos == 0)
    {
        return 0;
    }
    else if (pos == 1)
    {
        return 1;
    }
    // recursion
    return ComputeFibonacci(pos - 1) + ComputeFibonacci(pos - 2);
}

// to print the sequence
void PrintSequence(int pos)
{
    for (int i = 0; i <= pos; i++)
    {
        cout << ComputeFibonacci(i) << " ";
    }
}

int main()
{
    int pos;
    cout << "Enter a position you want to compute fibonacci for: ";
    cin >> pos;

    if (pos >= 0)
    {
        cout << "The fibonacci sequence from position 0 till position n is:" << endl;
        PrintSequence(pos);
        cout << endl;
    }

    else
    {
        cout << "Invalid position. Please enter a non-negative integer position." << endl;
    }

    return 0;
}