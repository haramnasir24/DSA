// implement queue using array based circular queue

#include <iostream>
using namespace std;

#define size 5
class CircularQueue
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
    CircularQueue()
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
                rear = (rear + 1) % size;
                queue[rear] = value;
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
            front = (front + 1) % size;
            length--;
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
            if (rear < front)
            {

                for (int i = front; i < size; i++)
                {
                    cout << queue[i] << " ";
                }

                for (int i = 0; i <= rear; i++)
                {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }

            // front == rear or rear > front
            else
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Queue is empty." << endl;
        }
    }
};

int main()
{
    CircularQueue Q;
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

    Q.Enqueue(35);
    Q.Enqueue(55);
    Q.Dequeue();

    Q.DisplayQueue();

    // cout << Q.front << endl;
    // cout << Q.rear;

    return 0;
}
