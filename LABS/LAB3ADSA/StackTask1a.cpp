// stack implementation using array

#include <iostream>
using namespace std;

#define size 5
class Stack
{
    public:
    int array[size];
    int length;
    int top;

    // constructor
    Stack()
    {
        length = 0;
        top = -1;
    }

    // functions
    bool isEmpty()
    {
        return length == 0; // top == -1
    }

    bool isFull()
    {
        return length == size; // top == size-1
    }

    // pushes an element on the top of a stack
    void push(int value)
    {
        if (!isFull())
        {
            array[++top] = value;
            length++;
        }
        else
        {
            cout << "Stack is full." << endl;
        }
    }

    // removes and returns the element stored on the top of a stack
    int pop()
    {
        if (!isEmpty())
        {
            int popped = array[top];
            top--;
            length--;
            return popped;
        }
        else
        {
            return -1;
        }
    }

    // displays the content stored at the top end of a non-empty stack without removing it.
    void peek() // top()
    {
        if (!isEmpty())
        {
            cout << "Top element in the stack is: " << array[top] << endl;
        }
        else
        {
            cout << "Stack is empty." << endl;
        }
    }

    void Display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < length; i++)
                cout << array[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "Stack is empty." << endl;
        }
    }
};

int main()
{
    Stack S;
    S.push(12);
    S.push(13);
    S.push(15);
    S.push(11);
    S.push(10);
    S.push(9);

    S.Display();

    S.peek();

    cout << "The popped elements are: ";
    cout << S.pop() << " ";
    cout << S.pop() << endl;

    S.Display();
    S.peek();

    return 0;
}