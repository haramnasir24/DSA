// Implement a function that rearranges a singly linked list by reversing its order
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

public:
    // constructor
    SinglyLinkedList()
    {
        head = NULL;
        last = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void InsertSorted(int value)
    {
        // create a new node
        Node *newNode = new Node();
        newNode->data = value;

        if (isEmpty())
        {
            newNode->next = head;
            head = newNode;
            length++;
        }
        else
        {
            SearchNode(value);
            if (temp == NULL)
            {
                loc = head;
                ploc = NULL;

                while (loc != NULL && loc->data < value)
                {
                    ploc = loc;
                    loc = loc->next;
                }
                if (ploc == NULL)
                {
                    newNode->next = loc;
                    head = newNode;
                    length++;
                }
                else if ((ploc != NULL) && (loc != NULL))
                {
                    newNode->next = loc;
                    ploc->next = newNode;
                    length++;
                }
                else
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
        return NULL; 
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

    Node* ReverseList(Node* node)
    {
        // Base cases
        if (node == NULL) // empty list
            return NULL;
        if (node->next == NULL) {
            head = node;
            return node;
        }
        Node* node1 = ReverseList(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }
};

int main()
{
    SinglyLinkedList SLL; // OBJECT OF SLL CLASS

    // creating sorted linked list
    SLL.InsertSorted(13);
    SLL.InsertSorted(15);
    SLL.InsertSorted(1);
    SLL.InsertSorted(3);
    SLL.InsertSorted(10);
    SLL.InsertSorted(13);

    cout << "ORIGINAL LIST: ";
    SLL.DisplayList();
    cout << "LIST AFTER REVERSAL: ";
    SLL.ReverseList(SLL.head);
    SLL.DisplayList();

    return 0;
}