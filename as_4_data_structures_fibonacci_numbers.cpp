#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
//==================================================
//Title: Assignment 1, Stack Implemented Array
//Algorithm: N/A
//Pre-conditions:
//Post-conditions:
//Exceptions:
//Programmer: Jake Sauter
//Date: 10/05/2015
//Version: 1.0
//--------------------------------------------------
int RecursiveFib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else

    {
        return RecursiveFib(n-1) + RecursiveFib(n-2);
    }
}
//--------------------------------------------------
int NonRecursiveFib(int n)
{
    double prev = -1;
	double result = 1;
	double sum;
	int i;

	for(i = 0;i <= n;i++)
	{
		sum = result + prev;
		prev = result;
		result = sum;
	}

	return result;
}
//--------------------------------------------------
void printMenu()
{
    cout << "Please choose from the given menu" << endl;
    cout << "1. Recursive Fibonacci Numbers" << endl;
    cout << "2. NonRecursive Fibonacci Numbers" << endl;
    cout << "Please enter your menu choice: ";
}
//--------------------------------------------------
int main()
{
    int choice, index, fibNum;
    clock_t startTime, endTime;
    double time;
    printMenu();
    cin >> choice;
    cout << "\nPlease enter the index of the Fibonacci number that you want: ";
    cin >> index;
    switch(choice)
    {
        case 1:
            startTime = clock();
            fibNum = RecursiveFib(index);
            endTime = clock();
            break;
        case 2:
            startTime = clock();
            fibNum = NonRecursiveFib(index);
            endTime = clock();
            break;
    }
    time = (endTime-startTime)/double(CLOCKS_PER_SEC);
    cout << "The number in the Fibonacci sequence at this index is: " << fibNum << endl;
    cout << fixed << setprecision(3) << "The run time of this program was " << time << " seconds" << endl;
    return 0;
}

