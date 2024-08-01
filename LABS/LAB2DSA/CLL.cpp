#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
public:
    Node *list; // LAST NODE THAT POINTS TO HEAD
    Node *loc;
    Node *ploc;
    Node *temp;
    int length;

public:
    // constructor
    CircularLinkedList() // creates empty list
    {
        list = NULL;
        length = 0;
    }

    // destructor
    ~CircularLinkedList() // destroys list
    {
        list = NULL;
        length = 0;
    }

    // checks whether the list is empty or not. Returns true if empty and false otherwise
    bool isEmpty()
    {
        return list == NULL; // or length == 0
    }

    // takes input from a user and inserts it at the front of a list
    void InsertAtFront(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (isEmpty())
        {
            newNode->next = newNode; // points to itself since only node
            list = newNode;
            length++;
        }

        else
        {
            newNode->next = list->next;
            list->next = newNode;
            length++;
        }
    }

    // takes input from a user and inserts it at the tail end of a list
    void InsertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        // if list is empty
        if (isEmpty())
        {
            newNode->next = newNode;
            list = newNode;
            length++;
        }

        else
        {
            newNode->next = list->next;
            list->next = newNode;
            list = newNode;
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

        if (isEmpty())
        {
            newNode->next = newNode; // points to itself
            list = newNode;
            length++;
        }

        // not empty
        else
        {
            SearchNode(value);
            if (temp == NULL) // insert only if value not present already
            {
                loc = list->next;
                ploc = list;

                // traversing the list
                while (loc != list && loc->data < value)
                {
                    ploc = loc;
                    loc = loc->next;
                }

                // only one element in the list at the moment
                if ((ploc == list) && (loc == list))
                {
                    // insertion at front
                    if (loc->data > value)
                    {
                        newNode->next = list;
                        list->next = newNode;
                        length++;
                    }
                    // insertion after first node
                    else
                    {
                        newNode->next = list;
                        list->next = newNode;
                        list = newNode;
                        length++;
                    }
                }

                else if ((ploc != list) && (loc == list))
                {
                    // insertion at end
                    if (loc->data < value)
                    {
                        newNode->next = list->next;
                        list->next = newNode;
                        list = newNode;
                        length++;
                    }
                    // insertion before end node
                    // if loc->data > value
                    else
                    {
                        newNode->next = ploc->next;
                        ploc->next = newNode;
                        length++;
                    }
                }

                // insertion in middle
                // ploc !=list and loc !=list
                // and when ploc == list and loc == list -> next (insertion at front when list contains more than one elements)
                else
                {
                    newNode->next = ploc->next;
                    ploc->next = newNode;
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
            loc = list->next;
            ploc = list;
            temp = NULL;
            while (loc != list)
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

            // for the end node or the only node
            if (loc == list)
            {
                if (loc->data == value)
                {
                    temp = loc;
                    return temp;
                }
                else
                {
                    return temp;
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
            SearchNode(value);
            if (temp != NULL) // value found in the list
            {

                // deleting the only node
                if (list->next == list)
                {
                    list = NULL;
                    delete list;
                    length--;
                }

                // deleting first node
                else if ((ploc == list) && (loc == list->next)) // loc == list->next
                {
                    ploc->next = loc->next; // it is not ploc -> next = loc -> next since ploc isnt a node yet
                    loc = NULL;
                    delete loc;
                    length--;
                }

                // deleting middle node
                else if ((ploc != list) && (loc != list))
                {
                    ploc->next = loc->next;
                    loc = NULL;
                    delete loc;
                    length--;
                }

                // deleting last node
                else if ((ploc != list) && (loc == list))
                {
                    ploc->next = loc->next;
                    loc = NULL;
                    delete loc;
                    list = ploc;
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
            temp = list->next;
            while (temp != list)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }

            if (temp == list)
            {
                cout << temp->data;
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
            while (list->next != list) // not null
            {
                temp = list->next;
                list->next = list->next->next;
                temp = NULL;
                delete temp;
            }
            if ((list->next) == list) // also caters single element list
            {
                list = NULL;
                delete list;
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
    CircularLinkedList CLL; // OBJECT OF SLL CLASS

    // creating unsorted linked list
    // CLL.InsertAtFront(12);
    // CLL.InsertAtFront(13);
    // CLL.InsertAtEnd(9);
    // CLL.InsertAtFront(17);
    // CLL.InsertAtEnd(10);
    // CLL.InsertAtFront(15);

    // creating sorted linked list
    CLL.InsertSorted(13);
    CLL.InsertSorted(20);
    CLL.InsertSorted(12);
    CLL.InsertSorted(15);
    CLL.InsertSorted(10);
    // CLL.InsertSorted(13);

    // printing the list
    CLL.DisplayList();

    // Deleting nodes
    CLL.DeleteNode(13);
    CLL.DeleteNode(15);
    // CLL.DeleteNode(12);

    CLL.DisplayList();

    // Destroying list
    CLL.DestroyList();
    CLL.DisplayList();

    return 0;
}