// implement the algorithm that solves a mathematical expression
// stored in the postfix notation using stack

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

    // two stack algorithm
    // solves the postt-fix expression and stores the output in the stack
    void EvaluatePostfix(string Postfix)
    {
        int operand1;
        int operand2;
        int output;
        char number;
        for (int i = 0; i < Postfix.length(); i++)
        {

            if (isOperand(Postfix[i]))
            {
                // converting char to int
                push(Postfix[i] - '0');
            }

            // operator
            else
            {
                // pop the operands
                operand2 = pop();
                operand1 = pop();

                char token = Postfix[i];

                // performing operation
                if (token == '*')
                {
                    output = operand1 * operand2;
                }
                else if (token == '/')
                {
                    output = operand1 / operand2;
                }
                else if (token == '+')
                {
                    output = operand1 + operand2;
                }
                else if (token == '-')
                {
                    output = operand1 - operand2;
                }
                else if (token == '^')
                {
                    output = operand1 ^ operand2;
                }
                // storing result in the stack
                push(output);
            }
        }

        cout << "The result of the post-fix expression would be: " << pop() << endl;
    }

    // helper function
    bool isOperand(char token)
    {
        return !(token == '+' || token == '-' || token == '/' || token == '*' || token == '^' || token == ' ');
    }
};

int main()
{
    Stack S;
    string Postfix = "234*+82/-";
    S.EvaluatePostfix(Postfix);

    return 0;
}


