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
    // Node *last;
    Node *loc;
    Node *ploc;
    Node *temp;
    Node *temp2;
    int length;
    int product;
    int sum;
    int count;
    int largest;
    int smallest;

public:
    SinglyLinkedList() // creates empty list
    {
        head = NULL;
        length = 0;
    }

    ~SinglyLinkedList() // destroys list
    {
        head = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return head == NULL; // or length == 0
    }

    void InsertNode(int value) // at front, middle, or last by finding its logical position in the list
                               // makes a sorted list
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
                head = newNode;
                length++;
            }

            // insertion in middle or insertion at last
            if (ploc != NULL)
            {
                newNode->next = loc;
                ploc->next = newNode;
                length++;
            }
        }
    }

    Node *SearchNode(int value)
    {
        if (!isEmpty())
        {
            loc = head;
            ploc = NULL;
            while (loc != NULL && loc->data < value)
            {
                ploc = loc;
                loc = loc->next;
            }

            // at front
            if (ploc == NULL)
            {
                if (loc->data == value)
                {
                    return loc;
                }
                else
                {
                    loc = NULL;
                    return loc;
                }
            }

            // in the middle or at last
            // loc has to be non null
            // because traversing happens till loc is NULL, required only for insertion after last node
            // while we cant search beyond last node
            else if (ploc != NULL && loc != NULL)
            {
                if (loc->data == value)
                {
                    return loc;
                }
                else
                {
                    loc = NULL;
                    return loc;
                }
            }
        }
        return NULL; // empty list
    }

    void DeleteNode(int value)
    {
        if (!isEmpty())
        {
            loc = head;
            ploc = NULL;
            // traversing to find logical position of node to be deleted
            while (loc != NULL && loc->data < value)
            {
                ploc = loc;
                loc = loc->next;
            }

            // deleting first node
            if (ploc == NULL)
            {
                if (loc->data == value)
                {
                    ploc = loc->next; // it is not ploc -> next = loc -> next since ploc isnt a node yet
                    loc = NULL;
                    delete loc;
                    head = ploc;
                    length--;
                }
                else if (loc->data != value)
                {
                    cout << "value not found." << endl;
                }
            }

            // deleting middle node or last node
            else if (ploc != NULL && loc != NULL)
            {
                if (loc->data == value)
                {
                    ploc->next = loc->next;
                    loc = NULL;
                    delete loc;
                    length--;
                }
                else if (loc->data != value)
                {
                    cout << "value not found." << endl;
                }
            }

            // node not in the list (for nodes greater than last node idfk why)
            else
            {
                cout << "value not found." << endl;
            }
        }
        else
        {
            cout << "list is empty." << endl;
        }
    }

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
            cout << "list is empty." << endl;
        }
    }

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
        }

        else
        {
            cout << "No list to destroy." << endl;
        }
    }

    // finds product of nodes of SLL
    void ProductNodes()
    {
        if (!isEmpty())
        {
            // initializing the product variable
            product = 1;
            temp = head;
            while (temp != NULL)
            {
                product = product * (temp->data);
                temp = temp->next;
            }
            cout << "The product of nodes is: " << product << endl;
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    // finds sum of nodes
    void SumNodes()
    {
        if (!isEmpty())
        {
            sum = 0;
            temp = head;
            while (temp != NULL)
            {
                sum = sum + (temp->data);
                temp = temp->next;
            }
            cout << "The sum of nodes is: " << sum << endl;
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    // finds product of alternate nodes of SLL
    void ProductAlternate()
    {
        if (!isEmpty())
        {
            // initializing the product variable
            product = 1;
            temp = head;
            while (temp != NULL)
            {
                product = product * (temp->data);
                temp = temp->next->next;
            }
            cout << "The product of alternate nodes is: " << product << endl;
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    // find common nodes between two singly linked lists
    void IntersectionNodes(Node *head1, Node *head2)
    {
        if (!isEmpty())
        {
            temp = head;
            temp2 = head;
            while (temp != NULL)
            {
                while (temp2 != NULL)
                {
                    if ((temp2->data) == (temp->data))
                    {
                        count++;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
            cout << "common nodes are: " << count << endl;
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    void LargestElement()
    {
        if (!isEmpty())
        {
            temp = head;
            while (temp != NULL)
            {
                if ((temp->data) > ((temp2->next)->data))
                {
                    cout << temp->data;
                }
            }
        }
        else
        {
            cout << "List is empty." << endl;
        }
    }

    void SmallestElement();
    void ReverseLinkedList()
    {
        Node *previous = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        // cout << head->data;
    }
    void FindEvenNodes();
    void FindOddNodes();
    void InsertNodeAnywhereExceptHeadOrTail();

    void printLargestSmallestLinkedList(Node *head)
    {
        int maxElement = head->data;
        int minElement =  head->data;
        while (head != NULL)
        {
            if (minElement > head->data)
                minElement = head->data;
            if (maxElement < head->data)
                maxElement = head->data;
            head = head->next;
        }
        cout << minElement << endl;
        cout << maxElement << endl;
    }
    };

    int main()
    {

        Node *head;
        SinglyLinkedList SLL; // OBJECT OF SLL CLASS
        SLL.InsertNode(5);
        SLL.InsertNode(2);
        SLL.InsertNode(1);
        SLL.InsertNode(3);
        SLL.InsertNode(10);
        SLL.InsertNode(7);
        SLL.DisplayList();
        cout << endl;
        SLL.printLargestSmallestLinkedList(head);

        // SinglyLinkedList SLL2; // OBJECT OF SLL CLASS
        // SLL2.InsertNode(4);
        // SLL2.InsertNode(5);
        // SLL2.InsertNode(10);
        // SLL2.InsertNode(6);
        // SLL2.InsertNode(9);
        // SLL2.InsertNode(17);
        // SLL2.DisplayList();
        // SLL.ReverseLinkedList();
        // SLL.DisplayList();

        // SLL.IntersectionNodes(SLL, SLL2);

        // SLL.ProductNodes();
        // SLL.SumNodes();
        // SLL.ProductAlternate();
        // cout << SLL.SearchNode(1) << endl;
        // cout << SLL.length << endl;
        // SLL.DeleteNode(1);
        // SLL.DisplayList();
        // cout << SLL.length << endl;
        // SLL.DeleteNode(10000);
        // SLL.DisplayList();
        // cout << SLL.length << endl;
        // SLL.DestroyList();
        // SLL.DisplayList();

        return 0;
    }