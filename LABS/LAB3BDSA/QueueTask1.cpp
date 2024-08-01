// implement queue using array based linear queue

#include <iostream>
using namespace std;

#define size 5
class LinearQueue
{
    // fixed size array
public:
    int queue[size];

    // indexes to keep track of first and last positions in queue
    int front;
    int rear;

    // keeps track of number of elements in the array
    int length;
    int temp;

    // constructor
    LinearQueue()
    {
        front = -1;
        rear = -1;
        length = 0;
    }

    // functions
    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == size;
    }

    void Enqueue(int value)
    {
        if (!isFull())
        {
            // empty queue
            if (length == 0)
            {
                queue[++front] = value;
                rear++;
                length++;
            }
            else
            {
                queue[++rear] = value;
                length++;
            }
        }
        else
        {
            cout << "Queue is full." << endl;
        }
    }

    void Dequeue()
    {
        if (!isEmpty())
        {
            temp = queue[front];
            // increment front here front++;
            length--;
            
            // shifting elements to left
            for (int i = 0; i < rear; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
            cout << "The element " << temp << " has been removed from queue." << endl;
        }
        else
        {
            cout << "Queue is empty." << endl;
        }
    }

    void DisplayQueue()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < length; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Queue is empty." << endl;
        }
    }
};

int main()
{
    LinearQueue Q;
    Q.Enqueue(12);
    Q.Enqueue(13);
    Q.Enqueue(16);
    Q.Enqueue(20);
    Q.Enqueue(10);
    Q.Enqueue(15);

    Q.DisplayQueue();

    Q.Dequeue();
    Q.Dequeue();

    Q.DisplayQueue();

    return 0;
}
