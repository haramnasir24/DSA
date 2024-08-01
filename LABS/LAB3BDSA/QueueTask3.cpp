// You have to implement a waiting room management system in an emergency ward of a hospital.
// Your program will assign an Id number to a patient in a first come first serve basis.
// The lower the id, the sooner the service will be provided to the patient.
// using an array based circular queue.

#include <iostream>
#include <algorithm>
using namespace std;

struct patient
{
    int patientID;
    string patientName;
};

#define size 10
class CircularQueue
{
public:
    patient WaitingRoom[size];

    // indexes to keep track of first and last positions in waiting room
    int front;
    int rear;

    // keeps track of number of patients in the waiting room
    int length;

    patient temp;

    // constructor
    CircularQueue()
    {
        front = -1;
        rear = -1;
        length = 0; // room is empty
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

    // This method returns true if no one is waiting, otherwise, returns false.
    bool CanDoctorGoHome()
    {
        return length == 0;
    }

    // This method assigns an Id (which is auto-generated) to a patient
    // and register him/her to the system.
    void RegisterPatient(string name)
    {
        // to auto generate patient ids
        int id = length + 1;

        patient patientData; // an instance of patient struct
        patientData.patientName = name;
        patientData.patientID = id;

        if (!isFull())
        {
            // empty queue
            if (length == 0)
            {
                WaitingRoom[++front] = patientData;
                rear++;
                length++;
            }
            else
            {
                rear = (rear + 1) % size;
                WaitingRoom[rear] = patientData;
                length++;
            }
        }
        else
        {
            cout << "Waiting Room is full." << endl;
        }
    }

    // This method calls a patient to provide hospital service to him/her.
    void ServePatient()
    {
        if (!isEmpty())
        {
            temp = WaitingRoom[front];
            front = (front + 1) % size;
            length--;
            cout << "The patient " << temp.patientName << " from the waiting room has been served." << endl;
        }
        else
        {
            cout << "Waiting room is empty." << endl;
        }
    }

    // This method shows all ids of the waiting patients in SORTED order.
    // [Sorted according to their names]
    void ShowAllPatient()
    {
        if (!isEmpty())
        {
            cout << "The patient ids in sorted order are: ";
            for (int i = 0; i < length; i++)
            {
                cout << WaitingRoom[i].patientID << " ";
            }

            cout << endl;
        }
        else
        {
            cout << "Waiting room is empty." << endl;
        }
    }

    void DisplayQueue()
    {
        if (!isEmpty())
        {
            cout << "The patients in the waiting room are: ";
            if (rear < front)
            {
                for (int i = front; i < size; i++)
                {
                    cout << WaitingRoom[i].patientName << " ";
                    
                }

                for (int i = 0; i <= rear; i++)
                {
                    cout << WaitingRoom[i].patientName << " ";
                }
                cout << endl;
            }

            // front == rear or rear > front
            else
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << WaitingRoom[i].patientName << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Waiting room is empty." << endl;
        }
    }

    // This method cancels all appointments of the patients so that the doctor can go to lunch
    void CancelAll()
    {
        front = -1;
        rear = -1;
        length = 0;

        cout << "All the appointments have been cancelled, the doctor can go to lunch!" << endl;
    }
};

int main()
{
    CircularQueue Q;
    patient patientData;

    Q.RegisterPatient("Haram");
    Q.RegisterPatient("Eman");
    Q.RegisterPatient("Mahnoor");
    Q.RegisterPatient("Maha");
    Q.RegisterPatient("Uswa");
    Q.DisplayQueue();

    Q.ServePatient();
    Q.ServePatient();

    Q.DisplayQueue();
    Q.CancelAll();

    Q.DisplayQueue();

    if (Q.CanDoctorGoHome())
    {
        cout << "There is no patient waiting, the doctor can go home!" << endl;
    }

    else
    {
        cout << "There are patients waiting, the doctor can not go home!" << endl;
    }

    return 0;
}


