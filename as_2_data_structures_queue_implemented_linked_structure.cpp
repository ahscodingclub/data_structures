#include <iostream>

using namespace std;

//==================================================
//Title: Assignment 2, Queue Implemented Linked Structure
//Algorithm: N/A
//Pre-conditions:
//Post-conditions: A queue is dynamically created/changed by using menu options with the queue functions that the user selects at runtime.
//Exceptions: Non-Integer validation is not performed
//Programmer: Jake Sauter
//Date: 9/29/2015
//Version: 1.0
//--------------------------------------------------
struct node
{
    int info;
    node* next;
};

class QueueType
{
public:
    QueueType();
    ~QueueType();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(int newItem);
    void Dequeue(int& item);
    void MakeEmpty();
    void Print();
private:
    node* qFront;
    node* qRear;
};

//member function definitions for class QueueType

QueueType::QueueType()
{
   qFront = NULL;
   qRear = NULL;
}

QueueType::~QueueType()
{
    MakeEmpty();
}

void QueueType::MakeEmpty()
{
    node* tempPtr;
    while(qFront != NULL)
    {
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = NULL;//the queue is empty and the rear must be null
}

//IsEmpty function to check if the queue is empty. Because the front of the queue
bool QueueType::IsEmpty()
{
    return (qFront == NULL);
}

//IsFull function to check if the queue is full. Creating a node and checking to see if that node was successfully created
bool QueueType::IsFull()
{
    node* tempPtr = new node;
    if(tempPtr == NULL)
    {
        return true;
    }
    else
    {
        delete tempPtr;
        return false;
    }
}

//need to analyze this function more
void QueueType::Enqueue(int newItem)
{
    node* ptr;
    ptr = new node;
    ptr->info = newItem;
    ptr->next = NULL;
    if(qRear == NULL)
    {
        qFront = ptr;
    }
    else
    {
        qRear->next = ptr;
    }
    qRear = ptr;
}

//need to analyze this function more
void QueueType::Dequeue(int& item)
{
    if(!IsFull())
    {
        node* tempPtr;
        tempPtr = qFront;
        item = qFront->info;
        qFront = qFront->next;
        if(qFront == NULL)
        {
            qRear = NULL;
        }
        delete tempPtr;
    }
    else
    {
        cout << "Nothing to Dequeue!!, Your Queue is empty!" << endl << endl;
    }
}

void QueueType::Print()
{
    node* tempPtr;
    int item;
    cout << "The elements of the queue are: ";
    tempPtr = qFront;
    while(tempPtr != NULL)
    {
        item = tempPtr->info;
        cout << item << " ";
        tempPtr = tempPtr->next;
    }
    cout << endl << endl;
}

void printMenu()
{
    cout << "1. MakeEmpty" << endl;
    cout << "2. IsEmpty" << endl;
    cout << "3. IsFull" << endl;
    cout << "4. Enqueue" << endl;
    cout << "5. Dequeue" << endl;
    cout << "6. Print" << endl;
    cout << "Please enter your choice: ";
}

int main()
{
    //Main Function
    //Input parameters: User inputs menu selection and any further information needed from that menu choice
    //Output parameters: The result of the menu choice that the user has selected
    int i;
    QueueType myQueue;
    int choice, var;
    do
    {
        printMenu();
        cin >> choice;
        cout << endl;
        switch(choice)
        {
        case 1: myQueue.MakeEmpty();
            break;
        case 2: if(myQueue.IsEmpty())
                {
                    cout << "The Queue is empty" << endl << endl;
                }
                else
                {
                    cout << "The Queue is not empty" << endl << endl;
                }
            break;
        case 3: if(myQueue.IsFull())
                {
                    cout << "The Queue is full" << endl << endl;
                }
                else
                {
                    cout << "The Queue is not full" << endl << endl;
                }
            break;
        case 4: cout << "Please enter an int to be enqueued: ";
                cin >> var;
                cout << endl;
                myQueue.Enqueue(var);
            break;
        case 5:
            if(!myQueue.IsEmpty())
            {
                myQueue.Dequeue(var);
                cout << "The element Dequeued was: " << var << endl << endl;
            }
            else
            {
                cout << "There is nothing in the Queue!" << endl;
            }
            break;
        case 6: myQueue.Print();
            break;
        }
    }
    while(choice < 7 && choice > 0);

    cout  << "Thank you for using Queue, if the line is long, remember to \"Q UP!\"" << endl;
    return 0;
}
