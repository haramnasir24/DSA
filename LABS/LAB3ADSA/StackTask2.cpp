// balancing the braces in an expression using an array based stack

#include <iostream>
using namespace std;

#define size 500
class Stack
{
public:
    // character array type stack to store braces
    char stack[size];
    int length;
    int top;    // index
    bool valid; // to evaluate

    // constructor
    Stack()
    {
        length = 0;
        top = -1;
        valid = true;
    }

    // functions
    bool EvaluateExpression(string expression)
    {
        for (int i = 0; i < expression.length(); i++)
        {
            // opening braces
            if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            {
                push(expression[i]);
            }

            // closing braces
            else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
            {
                if (isEmpty())
                {
                    valid = false;
                    break;
                }
                char symb = pop();

                // check if braces match
                if ((expression[i] == ')' && symb != '(') || (expression[i] == ']' && symb != '[') || (expression[i] == '}' && symb != '{'))
                {
                    valid = false;
                    break;  
                }
            }
        }

        // check if stack is empty, return false if not
        if (!isEmpty())
        {
            valid = false;
        }
        return valid;
    }

    bool isEmpty()
    {
        return length == 0; // top == -1
    }

    bool isFull()
    {
        return length == size; // top == size-1
    }

    // pushes an element on the top of a stack
    void push(char symb)
    {
        if (!isFull())
        {
            stack[++top] = symb;
            length++;
        }
        else
        {
            cout << "Stack is full." << endl;
        }
    }

    // removes and returns the element stored on the top of a stack
    char pop()
    {
        if (!isEmpty())
        {
            char popped = stack[top];
            top--;
            length--;
            return popped;
        }
        else
        {
            return '\0';
        }
    }
};

int main()
{
    Stack S;
    string expression;

    cout << "Enter an expression: " << endl;
    cin >> expression;

    if (S.EvaluateExpression(expression) == 1)
    {
        cout << "The expression is correct!" << endl;
    }
    else
    {
        cout << "The expression is not correct!" << endl;
    }

    return 0;
}