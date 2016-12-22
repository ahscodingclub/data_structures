#include <iostream>

using namespace std;

//==================================================
//Title: Assignment 1, Stack Implemented Array
//Algorithm: N/A
//Pre-conditions: A max number of items allowed in the stack defined globally in the program. The queue is created to hold only integer values
//Post-conditions: A stack is created/changed by using the menu options with stack functions that the user selects at run time
//Exceptions: Non-integer validation is not performed
//Programmer: Jake Sauter
//Date: 9/29/2015
//Version: 1.0
//--------------------------------------------------
const int MAX_ITEMS = 500;
//--------------------------------------------------
//defining stack structure
struct StackType
{
public:
    StackType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push(int newItem);
    void Pop(int& item);
    void Print();
private:
    int top;
    int array[MAX_ITEMS];
};
//--------------------------------------------------
StackType::StackType()
{
    top = -1;
}
//--------------------------------------------------
void StackType::MakeEmpty()
{
    top = -1;
}
//--------------------------------------------------
bool StackType::IsEmpty()
{
    return (top == -1);
}
//--------------------------------------------------
bool StackType::IsFull()
{
    return (top == MAX_ITEMS-1);
}
//--------------------------------------------------
void StackType::Push(int newItem)
{
    if(IsFull())
    {
        return;
    }
    else
    {
        top++;
        array[top] = newItem;
    }
}
//--------------------------------------------------
void StackType::Pop(int& item)
{
    if(!IsEmpty())
    {
        item = array[top];
        top--;
    }

}
//--------------------------------------------------
void StackType::Print()
{
    int x = top;
    cout << "The elements in the stack are: " << endl;
    for(int i=x;i>-1;i--)
    {
        cout << array[i] << endl;
    }
    cout << endl;
}
//--------------------------------------------------
void PrintMenu()
{
    cout << "1. MakeEmpty" << endl;
    cout << "2. IsEmpty" << endl;
    cout << "3. IsFull" << endl;
    cout << "4. Push" << endl;
    cout << "5. Pop" << endl;
    cout << "6. Print" << endl;
}
//--------------------------------------------------
int main()
{
    //Main Function
    //Input parameters: User inputs menu selection and any further information needed from that menu choice
    //Output parameters: The result of the menu choice that the user has selected
    StackType stack;
    int choice, x;
    do
    {
        PrintMenu();
        cout << "Please enter your choice: ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1: stack.MakeEmpty();
                break;
            case 2: if(stack.IsEmpty())
                    {
                        cout << "The stack is empty" << endl << endl;;
                    }
                    else
                    {
                        cout << "The stack is not empty" << endl << endl;
                    }
                break;
            case 3: if(stack.IsFull())
                    {
                        cout << "The stack is full" << endl << endl;
                    }
                    else
                    {
                        cout << "The stack is not full" << endl << endl;
                    }
                break;
            case 4: cout << "Enter a number to be pushed onto the stack: ";
                    cin >> x;
                    stack.Push(x);
                    cout << endl << endl;
                break;
            case 5:
                    if(!stack.IsEmpty())
                    {
                        stack.Pop(x);
                        cout << "The element Popped was: " << x << endl << endl;
                    }
                    else
                    {
                        cout << "There is nothing on the stack to pop!!" << endl << endl;
                    }
                break;
            case 6: stack.Print();
                break;
        }
    }while(choice > 0 && choice < 7);

    return 0;
}
