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

    Node *rearrangeLinkedList(Node *head)
    {
        if (!head || !head->next)
            return head;

        // Separate the odd and even positioned nodes
        Node *odd_head = head;
        Node *even_head = head->next;

        // Keep track of the last nodes of the odd and even lists
        Node *odd_last = odd_head;
        Node *even_last = even_head;

        Node *current = even_head->next;
        bool is_odd = true;

        while (current)
        {
            if (is_odd)
            {
                odd_last->next = current;
                odd_last = current;
            }
            else
            {
                even_last->next = current;
                even_last = current;
            }

            current = current->next;
            is_odd = !is_odd;
        }

        // Terminate the odd list and the even list
        odd_last->next = nullptr;
        even_last->next = nullptr;

        // Reverse the even list
        Node *prev = nullptr;
        current = even_head;

        while (current)
        {
            Node *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        // Connect the reversed even list before the odd list
        if (even_head)
            odd_last->next = prev;

        // Update the start and last pointers
        Node *start = head ? head : even_head;
        Node *last = odd_last ? odd_last : even_last;

        return start;
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
    SLL.DisplayList();

    Node *result = SLL.rearrangeLinkedList(SLL.head);
    cout << "\nRearranged Linked List:" << endl;
    SLL.DisplayList();

    return 0;
}