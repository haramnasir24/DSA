// recursive function to compute the factorial of a non-negative integer n

#include <iostream>
using namespace std;

unsigned long long int ComputeFactorial(int num)
{
    // base case
    if (num == 0 || num == 1)
    {
        cout << "Base case called" << endl;
        return 1;
    }

    // recursion
    cout << "function call" << endl;
    return num * ComputeFactorial(num - 1);
}

int main()
{
    int num;
    cout << "Enter a number you want to compute factorial of: ";
    cin >> num;

    if (num >= 0)
    {
        cout << "The factorial of the number " << num << " is:\n" << ComputeFactorial(num) << endl;
    }
    else
    {
        cout << "Invalid number. Please enter a non-negative number.";
    }

    return 0;
}