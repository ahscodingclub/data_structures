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
//----------------------------------
const int N = 500;
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
    private:
        int top;
        int array[N];
};
//----------------------------------
StackType::StackType()
{
    top = -1;
}
//----------------------------------
void StackType::push(int item)
{
    //if the stack is full you cannot push anything onto it
    if(!isFull())
    {
        top++;
        array[top] = item;
    }
}
//----------------------------------
void StackType::pop(int& item)
{
    //if the stack is empty you cannot pop anything off of it
    if(!isEmpty())
    {
        item = array[top];
        top--;
    }
}
//----------------------------------
bool StackType::isEmpty()
{
    return (top == -1);
}
//----------------------------------
bool StackType::isFull()
{
    return (top == N-1);
}
//----------------------------------
int StackType::countStackElements()
{
    return (top+1);
}
//----------------------------------
void StackType::print()
{
    int x = top;
    cout << "The elements in the stack are: " << endl;
    for(int i=x;i>-1;i--)
    {
        cout << array[i] << endl;
    }
    cout << endl;
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
