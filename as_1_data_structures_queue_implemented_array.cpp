#include <iostream>

using namespace std;

/*-------------------------------------------------------------
 *Title: Assignment 1, Stack Implemented Array
 *Algorithm: N/A
 *Pre-conditions: A max number of items allowed in the stack 
   defined globally in the program. The queue is created to 
   hold only integer values
 *Post-conditions: A stack is created/changed by using the menu 
   options with stack functions that the user selects at run time
 *Exceptions: Non-integer validation is not performed
 *Programmer: Jake Sauter
 *Date: 9/29/2015
 *Version: 1.0
-------------------------------------------------------------*/
const int MAX_QUEUE = 500;
/*-----------------------------------------------------------*/
struct QueueType
{
  public:
      QueueType();
      ~QueueType();
      bool isEmpty();
      bool isFull();
      void makeEmpty();
      void enqueue();
      void dequeue();
      void print();
  private:
      int front, rear, count;
      int array[MAX_QUEUE];
}; 
/*-----------------------------------------------------------*/
QueueType::QueueType()
{
  count = 0;
  front = -1;
  rear = -1;
}
/*-----------------------------------------------------------*/
void QueueType::makeEmpty()
{
  if(isEmpty())
  {
    return;
  }
  else
  {
    front = rear = -1;
    count = 0; 
  }
}
/*-----------------------------------------------------------*/
bool QueueType::isFull()
{
  if(rear == MAX_QUEUE)
  { 
  }
}

