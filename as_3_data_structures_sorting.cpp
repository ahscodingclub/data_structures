#include <iostream>

using namespace std;

//==================================================
//Title: Assignment 3, Sorting
//Algorithm: Insertion Sort, Selection Sort, Bubble Sort
//Pre-conditions:
//Post-conditions: A user inputted array that could be sorted if they select any of the sort function options
//Exceptions: Non-Integer validation is not performed
//Programmer: Jake Sauter
//Date: 9/29/2015
//Version: 1.0
//--------------------------------------------------
int size = 0, count = 0;
//--------------------------------------------------
void printMenu()
{
    cout << "---------------MENU---------------" << endl;
    cout << "1. Sort the list by using bubble sort" << endl;
    cout << "2. Sort the list by using selection sort" << endl;
    cout << "3. Sort the list by using insertion sort" << endl;
    cout << "4. Print" << endl;
    cout << "Please enter your choice here: ";
}
//--------------------------------------------------
void addItems(int arr[])
{
    int item;
    while(count!=size)
    {
        cout << "Please enter an integer to be stored at index " << (count) << ": ";
        cin >> item;
        if(count!=size)
        {
            arr[count] = item;
            count++;
        }
    }
    cout << endl;
}
//--------------------------------------------------
//bubble sort runs through the array multiple times and will compare side by side elements and switch them if they are in incorrect order
//we do not say that the list is sorted until there are no swaps needed after and execution
//we are using j to edit the size of the list that we have to sort because we know after every
//execution that the larges or smallest number (depending how we are sorting) "bubbled" to the top (end) of the list
void bubbleSort(int arr[])
{
    int temp, j=0;
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        j++;
        for(int i=0;i<size-j;i++)
        {
            if(arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = false;
            }
        }
    }
}
//--------------------------------------------------
//selection sort runs through the array once, with three variables, i, j and minPos
//i is the current index that will have the correct element after this run of the sort
//j is the value that traverses the array, looking for the correct value for the current index
//minPos is the saved index of the correct value for the current index i, at the end of j's traversal, we know that minPos needs be switched with arr[i]
void selectionSort(int arr[])
{
    int minPos, temp;
    for(int i=0;i<size-1;i++)
    {
        minPos = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j] < arr[minPos])
            {
                minPos = j;
            }
        }

        if(arr[minPos] < arr[i])
        {
            temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;
        }

    }
}
//--------------------------------------------------
//insertion sort runs though the array once and inputs the current index into the sorted portion of the list
//it does this through grabbing the current element, then checking if it is larger then the element before it
//if not it will decrement and compare until the element is at its correct index
void insertionSort(int arr[])
{
    int temp, j;
    for(int i=0;i<size;i++)
    {
        //we need to set j=i so that we can traverse the array looking for
        //the right location without losing the current index that we are
        //putting in the right place
        j=i;
        while(j>0 && arr[j] < arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
//--------------------------------------------------
void print(int arr[])
{
    for(int i=0;i<count;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}
//--------------------------------------------------
int main()
{
    //Main Function
    //Input parameters: User inputs menu selection and any further information needed from that menu choice
    //Output parameters: The result of the menu choice that the user has selected
    int choice;
    cout << "Please enter the size of the list you would like to enter and sort: ";
    cin >> size;
    cout << endl;
    int arr[size];
    do
    {
        addItems(arr);
        printMenu();
        cin >> choice;
        cout << endl << endl;
        switch(choice)
        {
            case 1: bubbleSort(arr);
                break;
            case 2: selectionSort(arr);
                break;
            case 3: insertionSort(arr);
                break;
            case 4: print(arr);
                break;
        }
    }while(choice > 0 && choice < 5);
    return 0;
}
