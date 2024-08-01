// stack implementation using linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top; // head node
    int length;
    Node *temp;

    // constructor
    Stack()
    {
        top = NULL;
        length = 0;
    }

    // functions
    bool isEmpty()
    {
        return top == NULL;
    }

    // pushes an element on the top of a stack
    // here top means head node
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        if (isEmpty())
        {
            newNode->next = top;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        length++;
    }

    // removes and returns the element stored on the top of a stack
    // removes head node always
    int pop()
    {
        if (!isEmpty())
        {
            temp = top;
            top = top->next;
            int val = temp->data;
            temp = NULL;
            delete temp;
            length--;
            return val;
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
            cout << "Top element in the stack is: " << top->data << endl;
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
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
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