#include <iostream>
//==============================
//Title:Test1q1
//Algorithm: N/A
//Pre-conditions:
//Post-conditions: A Stack is created and tested
//Exceptions:
//Programmer: Jake Sauter
//Date: 9/25/2015
//Version: 1.0

using namespace std;

int N = 500;
//----------------------------------
struct Node
{
    int data;
    Node* next;
};
//----------------------------------
class StackType
{
    public:
        StackType();
        void push(int item);
        void pop(int& item);
        bool isEmpty();
        bool isFull();
        int countStackElements();
        void print();
        ~StackType();
        int size;
    private:
        Node* topPtr;
};
//----------------------------------
StackType::StackType()
{
    topPtr = NULL;
    size = 0;
}
//----------------------------------
void StackType::push(int item)
{
    //you cannot push an element onto a full stack
    if(!isFull())
    {
        Node* location;//creates a new Node pointer
        location = new Node;//allocates memory for Node
        location->data = item;
        location->next = topPtr;
        topPtr = location;
        size++;
    }
}
//----------------------------------
void StackType::pop(int& item)
{
    //you cannot pop an element of an empty stack
    if(!isEmpty())
    {
        Node* tempPtr;
        tempPtr = topPtr;
        item = tempPtr->data;
        topPtr = topPtr->next;
        delete tempPtr;
        size--;
    }
}
//----------------------------------
bool StackType::isEmpty()
{
    return (topPtr == NULL);
}
//----------------------------------
bool StackType::isFull()
{
    return (size == N);
}
//----------------------------------
int StackType::countStackElements()
{
    return size;
}
//----------------------------------
void StackType::print()
{
   Node* temp;
   temp = topPtr;
   cout << "The current stack contains: " << endl;
   for(int i=0;i<size;i++)
   {
       cout << temp->data << endl;
       temp = temp->next;
   }
}
//----------------------------------
StackType::~StackType()
{
    int var;
    while(!isEmpty())
    {
        pop(var);
    }
}
//----------------------------------
int main()
{
       //creating a rightStack and leftStack
    StackType LeftStack;
    StackType RightStack;
    //pushing to LeftStack
    LeftStack.push(1);
    LeftStack.push(2);
    LeftStack.push(3);
    //pushing to RightStack
    RightStack.push(1);
    RightStack.push(2);
    RightStack.push(3);
    //counting the stack elements of left stack
    cout << "The amount of elements in the left stack is: " << LeftStack.countStackElements() << endl;
    //counting the stack elements of the right stack
    cout << "the amount of elements in the right stack is: " << RightStack.countStackElements() << endl;
     //checking isEmpty and  isFull after adding elements
    if(LeftStack.isEmpty())
    {
        cout << "The left stack is empty" << endl;
    }
    else
    {
        cout << "The left stack is not empty" << endl;
    }
    if(RightStack.isEmpty())
    {
        cout << "The right stack is empty" << endl;
    }
    else
    {
        cout << "The right stack is not empty" << endl;
    }
    if(LeftStack.isFull())
    {
        cout << "The left stack is full" << endl;
    }
    else
    {
        cout << "The left stack is not full" << endl;
    }
    if(RightStack.isFull())
    {
        cout << "The right stack is full" << endl;
    }
    else
    {
        cout << "The right stack is not full" << endl;
    }
    //printing the right stack
    RightStack.print();
    //printing the left stack
    LeftStack.print();
    //popping all of the elements off stack 1

    return 0;
}
