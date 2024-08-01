// recursive function that checks whether the given sequence of characters is a palindrome or not

#include <iostream>
#include <string>
using namespace std;

bool EvaluatePalindrome(string expression, int start, int end)
{
    // Base case: empty string or single character string is a palindrome
    if (start >= end)
    {
        return true; 
    }

    // start < end
    if (expression[start] == expression[end])
    {
        return EvaluatePalindrome(expression, start + 1, end - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    int length = expression.length();
    int start = 0;
    int end = length - 1;
    bool result;

    // one character strings are always palindrome
    if (length <= 1)
    {
        result = true;
    }
    else
    {
        result = EvaluatePalindrome(expression, start, end);
    }

    if (result == true)
    {
        cout << "Given expression is a palindrome!" << endl;
    }
    else
    {
        cout << "Given expression is not a palindrome!" << endl;
    }

    return 0;
}