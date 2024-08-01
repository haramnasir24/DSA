// from Infix notation to its equivalent postfix notation using stack

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
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
    void push(char token)
    {
        Node *newNode = new Node();
        newNode->data = token;
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
    char pop()
    {
        if (!isEmpty())
        {
            temp = top;
            top = top->next;
            char token = temp->data;
            temp = NULL;
            delete temp;
            length--;
            return token;
        }
        else
        {
            return '\0';
        }
    }

    // displays the content stored at the top end of a non-empty stack without removing it.
    char peek() // top()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            return '\0';
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

    // conversion function
    void InfixToPostfix(string infix)
    {
        Stack S;             // empty stack
        vector<char> output; // for the postfix expression

        for (int i = 0; i < infix.length(); i++)
        {
            char token = infix[i];

            // if operands
            if (isOperand(token))
            {
                // populating vector
                output.push_back(token);
            }

            // if operators
            else if (isOperator(token))
            {
                while (!S.isEmpty() && (Precedence(token) <= Precedence(S.peek())))
                {
                    output.push_back(S.pop());
                }
                // append the token to the stack
                S.push(token);
               
            }

            // dealing with braces
            else if (token == '(' || token == '{' || token == '[')
            {
                S.push(token);
            }

            else if (token == ')' || token == '}' || token == ']')
            {
                if (token == ')')
                {
                    while (S.peek() != '(')
                    {
                        output.push_back(S.pop());
                    }
                }

                else if (token == '}')
                {
                    while (S.peek() != '{')
                    {
                        output.push_back(S.pop());
                    }
                }

                else // else if (token == ']')
                {
                    while (S.peek() != '[')
                    {
                        output.push_back(S.pop());
                    }
                }
                // remove opening parentheses when found
                S.pop();
            }
        }

        // remove remaining operators from stack and append to output
        while (!S.isEmpty())
        {
            output.push_back(S.pop());
        }

        cout << "The corresponding post-fix expression would be: ";

        // printing the post-fix expression
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << " ";
        }
    }

    // helper functions
    bool isOperand(char token)
    {
        return !(token == '+' || token == '-' || token == '/' || token == '*' || token == '^' || token == '(' || token == ')' || token == '{' || token == '}' || token == '[' || token == ']');
    }

    bool isOperator(char token)
    {
        return (token == '+' || token == '-' || token == '/' || token == '*' || token == '^');
    }

    int Precedence(char token)
    {
        if (token == '+' || token == '-')
        {
            return 1;
        }
        else if (token == '/' || token == '*')
        {
            return 2;
        }
        else if (token == '^')
        {
            return 3;
        }
        return 0;
    }
};

int main()
{
    Stack S;
    string Infix;

    cout << "Enter an Infix expression: " << endl;
    cin >> Infix;
    S.InfixToPostfix(Infix);

    return 0;
}