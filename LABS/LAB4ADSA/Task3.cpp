// Suppose you have a singly linked list of size n.
// Implement a function takes a position number pos as input from the user,
// and returns the value stored at that position

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class SinglyLinkedList
{
public:
    Node *head;
    Node *last;
    Node *loc;
    Node *ploc;
    Node *temp;
    int length;
    int position;

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

    void InsertSorted(int value) // at front, middle, or last by finding its logical position in the list
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

    // This method should destroy all nodes of a linked list making it empty.
    // It should also free space allocated for all the nodes
    void DestroyList()
    {
        // this->~SinglyLinkedList(); // calling destructor
        if (!isEmpty())
        {
            while (head != NULL) // not null
            {
                temp = head;
                head = head->next;
                temp = NULL;
                delete temp;
            }
            cout << "List has been destroyed." << endl;
        }

        else
        {
            cout << "No list to destroy." << endl;
        }
    }

    // takes input from user and returns value at that position
    int ElementAtPosition(int pos)
    {
        if (!isEmpty())
        {
            temp = head;
            position = 1;
            if (pos > 0)
            {
                while (temp != NULL && position < pos)
                {
                    temp = temp->next;
                    position++;
                }

                if (temp != NULL)
                {
                    return temp->data;
                }

                else
                {
                    return -1;
                }
            }
            else{
                return -1;
            }
        }
        return -1;
    }
};

int main()
{
    SinglyLinkedList SLL; // OBJECT OF SLL CLASS
    int pos;

    // creating sorted linked list
    SLL.InsertSorted(13);
    SLL.InsertSorted(15);
    SLL.InsertSorted(1);
    SLL.InsertSorted(3);
    SLL.InsertSorted(10);

    // printing the list
    SLL.DisplayList();

    cout << "Enter a position number: ";
    cin >> pos;

    if (SLL.ElementAtPosition(pos) != -1)
    {
        cout << "The element at position " << pos << " in the linked list is: " << SLL.ElementAtPosition(pos) << endl;
    }

    else
    {
        cout << "Invalid position." << endl;
    }

    return 0;
}