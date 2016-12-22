#include <iostream>

using namespace std;

/*-------------------------------------------------------
* Title: Stack Implemented by Array
* Algorithm: N/A
* Pre-conditions: A max number of items allowed in the stack
  is defined globally. The stack is created to hold integer
  values.
* Post-conditions: A stack is created and manipulated with 
  menu options linked to standard stack operations.
* Exceptions: Non-integer validation is not performed
* Author: Jake Sauter 
* Date: 9/29/2015
* Version: 1.0
-------------------------------------------------------*/
const int MAX_ITEMS = 500;
/*-----------------------------------------------------*/
/* defining the stack structure */
struct StackType
{
  public: 
      StackType();
      void makeEmpty();
      bool isFull();
      bool isEmpty();
      void push(int newItem);
      void pop(int& item);
      void print();
  private: 
      int top;
      int array[MAX_ITEMS];
};
/*----------------------------------------------------*/
StackType::StackType()
{
  makeEmpty();
}
/*----------------------------------------------------*/
void StackType::makeEmpty()
{
  top = -1;
}
/*----------------------------------------------------*/
bool StackType::isEmpty()
{
  return ( top == -1 );
}
/*----------------------------------------------------*/
bool StackType::isFull()
{
  return ( top == MAX_ITEMS-1 );
}
/*----------------------------------------------------*/
void Stacktype::push(int newItem)
{
  if( isFull() )
  {
    return;
  }
  else 
  {
    top++;
    array[top] = newItem;
  }
}
/*----------------------------------------------------*/



