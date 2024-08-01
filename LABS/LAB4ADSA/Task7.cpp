#include <iostream>
using namespace std;

// NODE CLASS
class Node
{
public:
    int data;
    Node *next;
};

// STACK CLASS
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
};

// LINKED LIST CLASS
class SinglyLinkedList
{
public:
    Node *head;
    Node *last;
    Node *loc;
    Node *ploc;
    Node *temp;
    int length;

public:
    // constructor
    SinglyLinkedList() // creates empty list
    {
        head = NULL;
        last = NULL;
        length = 0;
    }

    // checks whether the list is empty or not. Returns true if empty and false otherwise
    bool isEmpty()
    {
        return head == NULL; // or length == 0
    }

    void InsertSorted(int value)
    // at front, middle, or last by finding its logical position in the list
    // makes a sorted list
    // assuming duplicate elements are not allowed
    {
        // create a new node
        Node *newNode = new Node();
        newNode->data = value;

        if (isEmpty())
        {
            newNode->next = head; // points to Null
            head = newNode;
            length++;
        }

        // not empty
        else
        {
            SearchNode(value);
            if (temp == NULL)
            {
                loc = head;
                ploc = NULL;

                // traversing the list
                while (loc != NULL && loc->data < value)
                {
                    ploc = loc;
                    loc = loc->next;
                }

                // insertion at front , also caters single element
                if (ploc == NULL) // or loc == head
                {
                    newNode->next = loc; // or = head
                    head = newNode;
                    length++;
                }

                // insertion in middle
                else if ((ploc != NULL) && (loc != NULL))
                {
                    newNode->next = loc;
                    ploc->next = newNode;
                    length++;
                }

                // insertion at last
                else // ploc !=NULL and loc == NULL
                {
                    newNode->next = loc;
                    ploc->next = newNode;
                    last = newNode;
                    length++;
                }
            }
            else
            {
                cout << "Node with the value " << value << " already exits, duplication not allowed." << endl;
            }
        }
    }

    // searches value in a list and returns the node
    // works for both sorted and unsorted list
    // returns 0 or NULL if element not found
    Node *SearchNode(int value)
    {
        if (!isEmpty())
        {
            loc = head;
            ploc = NULL;
            temp = NULL;
            while (loc != NULL)
            {
                if (loc->data == value)
                {
                    temp = loc;
                    return temp;
                }
                else
                {
                    ploc = loc;
                    loc = loc->next;
                }
            }
            if (temp == NULL)
            {
                return NULL;
            }
        }
        return NULL; // empty list
    }

    // This function prints all elements of a linked list starting from the first one.
    void DisplayList()
    {
        if (!isEmpty())
        {
            temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    // this function reverses order of elements in linked list using stack
    void ReverseLinkedListUsingStack(SinglyLinkedList SLL)
    {
        Stack S; // object of stack class
        temp = head;
        if (!SLL.isEmpty())
        {
            while (temp != NULL)
            {
                S.push(temp->data);
                temp = temp->next;
            }
            // Stack has been populated
            // now popping elements from stack and storing back in linked list

            if (!S.isEmpty())
            {
                temp = head;
                while (!S.isEmpty())
                {
                    temp->data = S.pop();
                    temp = temp->next;
                }
            }
        }
        else
        {
            cout << "Linked list doesnt exist." << endl;
        }
    }
};

int main()
{
    SinglyLinkedList SLL; // OBJECT OF SLL CLASS

    // creating sorted linked list
    SLL.InsertSorted(6);
    SLL.InsertSorted(7);
    SLL.InsertSorted(8);
    SLL.InsertSorted(9);
    SLL.InsertSorted(10);

    // printing the list
    cout << "Original Linked List: ";
    SLL.DisplayList();

    cout << "Reversed Linked List: ";
    SLL.ReverseLinkedListUsingStack(SLL);
    SLL.DisplayList();

    return 0;
}