#include <iostream>

using namespace std;

//==================================================
//Title: Assignment 2, Stack Implemented Linked Structure
//Algorithm: N/A
//Pre-conditions:
//Post-conditions: A stack is dynamically created/changed by using menu options with the stack functions that the user selects at runtime.
//Exceptions: Non-Integer validation is not performed
//Programmer: Jake Sauter
//Date: 9/29/2015
//Version: 1.0
//--------------------------------------------------
//need to make a node type to store into the stack
struct node
{
    int data;
    node* next;
};
//--------------------------------------------------
//class declaration for the stack
class StackType
{
    public:
        StackType(); //constructor
        ~StackType(); //destructor
        void MakeEmpty(); //for making the stack set to empty
        bool IsEmpty(); //for checking if the stack is empty
        bool IsFull() const; //for checking if the stack is full
        void Push(int item); //for adding a new item to the stack
        void Pop(int& item); //for taking an item off the stack
        void print();//for printing the stack
        int size;
    private:
        node* topPtr; //The top-most item on the stack
};
//--------------------------------------------------
//member function definitions for the class StackType
StackType::StackType()
{
    topPtr = NULL;
    size = 0;
}
//--------------------------------------------------
bool StackType::IsEmpty()
{
    return (topPtr == NULL);
}
//--------------------------------------------------
void StackType::Push(int newItem)
{
    node* location;//creates a new node pointer
    location = new node;//allocated memory for the r value of location to be stored
    location->data = newItem;
    location->next = topPtr;
    topPtr = location;
    size++;
}
//--------------------------------------------------
void StackType::Pop(int& item)
{
    if(!IsEmpty())
    {
        node* tempPtr;
        tempPtr = topPtr;
        item = tempPtr->data;
        topPtr = topPtr->next;
        delete tempPtr;
        size--;
    }
}
//--------------------------------------------------
bool StackType::IsFull() const
{
    node* tempPtr = new node;//creates a new node pointer and allocates a memory block for the info to be stored in
    if(tempPtr==NULL)
    {
        return true;
    }
    else
    {
        delete tempPtr;
        return false;
    }
}
//--------------------------------------------------
//tempPtr deletes the r value that tempPtr is currently pointing to, being the last stored top node
void StackType::MakeEmpty()
{
    node* tempPtr;
    while(topPtr!= NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}
//--------------------------------------------------
void StackType::print()
{
   node* temp;
   temp = topPtr;
   cout << "The current stack contains: " << endl;
   for(int i=0;i<size;i++)
   {
       cout << temp->data << endl;
       temp = temp->next;
   }
}
//--------------------------------------------------
StackType::~StackType()
{
    MakeEmpty();
}
//--------------------------------------------------
void printMenu()
{
    cout << "1. MakeEmpty" << endl;
    cout << "2. IsEmpty" << endl;
    cout << "3. IsFull" << endl;
    cout << "4. Push" << endl;
    cout << "5. Pop" << endl;
    cout << "6. Print" << endl;
    cout << "Please enter your choice: ";
}
//--------------------------------------------------
int main()
{
    //Main Function
    //Input parameters: User inputs menu selection and any further information needed from that menu choice
    //Output parameters: The result of the menu choice that the user has selected
    StackType Stack;
    int choice, var;
    do
    {
        printMenu();
        cin >> choice;
        cout << endl;
        switch(choice)
        {
        case 1: Stack.MakeEmpty();
            break;
        case 2: if(Stack.IsEmpty())
                {
                    cout << "The Stack is empty" << endl << endl;
                }
                else
                {
                    cout << "The Stack is not empty" << endl << endl;
                }
            break;
        case 3: if(Stack.IsFull())
                {
                    cout << "The Stack is full" << endl << endl;
                }
                else
                {
                    cout << "The Stack is not full" << endl << endl;
                }
            break;
        case 4: cout << "Please enter an int to be pushed: ";
                cin >> var;
                cout << endl;
                Stack.Push(var);
            break;
        case 5:
            if(!Stack.IsEmpty())
            {
                Stack.Pop(var);
                cout << var << endl;
            }
            else
            {
                cout << "There is nothing to pop!" << endl;
            }
            break;
        case 6:
            if(!Stack.IsEmpty())
            {
                Stack.print();
            }
            else
            {
                cout << "There are no elements in the stack to show!" << endl << endl;
            }
            break;
        }
    }
    while(choice < 7 && choice > 0);

    cout << "Thank you for using stack! Remember to come back often if you want to \"Stack Up\"! to the competition" << endl;

    return 0;
}

