#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
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
    DoublyLinkedList() // creates empty list
    {
        head = NULL;
        last = NULL;
        length = 0;
    }

    // destructor
    ~DoublyLinkedList() // destroys list
    {
        head = NULL;
        length = 0;
    }

    // checks whether the list is empty or not. Returns true if empty and false otherwise
    bool isEmpty()
    {
        return head == NULL; // or length == 0
    }

    // takes input from a user and inserts it at the front of a list
    void InsertAtFront(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        // if list is empty
        if (isEmpty())
        {
            // head is NULL
            newNode->next = head;
            newNode->prev = head;
            head = newNode;
            length++;
        }

        else
        {
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
            length++;
        }
    }

    // takes input from a user and inserts it at the tail end of a list
    void InsertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        // initilaizing last pointer by traversing to end of linked list
        if (head != NULL)
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            last = temp;
        }

        // if list is empty
        if (isEmpty())
        {
            newNode->next = head;
            newNode->prev = head;
            head = newNode;
            last = newNode;
            length++;
        }

        else
        {
            last->next = newNode;
            newNode->prev = last;
            newNode->next = NULL;
            last = newNode;
            length++;
        }
    }

    void InsertSorted(int value) // at front, middle, or last by finding its logical position in the list
    // makes a sorted list
    // assuming duplicate elements are not allowed
    {
        // create a new node
        Node *newNode = new Node();
        newNode->data = value;

        // initilaizing last pointer by traversing to end of linked list
        if (head != NULL)
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            last = temp;
        }

        if (isEmpty())
        {
            newNode->next = head; // points to Null
            newNode->prev = head;
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

                // insertion at front
                if (ploc == NULL) // or loc == head
                {
                    newNode->next = loc; // or = head
                    newNode->prev = ploc;
                    loc->prev = newNode;
                    head = newNode;
                    length++;
                }

                // insertion in middle or insertion at last
                else if ((ploc != NULL) && (loc != NULL))
                {
                    newNode->next = loc;
                    ploc->next = newNode;
                    loc->prev = newNode;
                    newNode->prev = ploc;
                    length++;
                }

                else
                {
                    newNode->next = loc;
                    ploc->next = newNode;
                    newNode->prev = ploc;
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

    // Find value using search method and if a node containing the searched value is found,
    // then delete it from the linked list.
    // Also free the allocated memory.
    void DeleteNode(int value)
    {
        if (!isEmpty())
        {
            // initilaizing last pointer by traversing to end of linked list
            if (head != NULL)
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                last = temp;
            }

            SearchNode(value);
            if (temp != NULL) // value found in the list
            {
                // deleting first node
                if (ploc == NULL)
                {
                    ploc = loc->next; // it is not ploc -> next = loc -> next since ploc isnt a node yet
                    loc = NULL;
                    delete loc;
                    head = ploc;
                    length--;
                }

                // deleting middle node or last node
                else if ((ploc != NULL) && (loc->next != NULL))
                {
                    ploc->next = loc->next;
                    loc->next->prev = ploc;
                    loc = NULL;
                    delete loc;
                    length--;
                }

                else
                {
                    ploc->next = loc->next;
                    loc = NULL;
                    delete loc;
                    last = ploc;
                    length--;
                }
            }
            else
            {
                cout << "Value not found." << endl;
            }
        }
        else
        {
            cout << "List is empty." << endl;
        }
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

    void ReverseDisplay()
    {
        if (!isEmpty())
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->prev;
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
};

int main()
{
    DoublyLinkedList DLL; // OBJECT OF SLL CLASS

    // creating unsorted linked list
    // DLL.InsertAtFront(12);
    // DLL.InsertAtFront(13);
    // DLL.InsertAtEnd(9);
    // DLL.InsertAtFront(17);
    // DLL.InsertAtEnd(10);
    // DLL.InsertAtFront(15);

    // creating sorted linked list
    DLL.InsertSorted(13);
    DLL.InsertSorted(15);
    DLL.InsertSorted(1);
    DLL.InsertSorted(3);
    DLL.InsertSorted(10);
    DLL.InsertSorted(13);

    // printing the list
    DLL.DisplayList();
    // DLL.DeleteNode(15);
    // DLL.DeleteNode(13);
    // DLL.DisplayList();
    // cout << SLL.length << endl;

    // DLL.DestroyList();
    DLL.ReverseDisplay();

    return 0;
}