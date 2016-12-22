#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
//==================================================
//Title: Assignment 4, Tower Of Hanoi
//Algorithm: First move n-1 disks from A to B recursively with the assistance of tower b. Next move disk n from A to C. Lastly move n-1 disks from B to C with the assistance of tower A
//Pre-conditions: A stack of rings in ascending size on tower A.
//Post-conditions: A stack of rings in ascending size on tower C.
//Exceptions: Non-Integer input verification not performed.
//Programmer: Jake Sauter
//Date: 10/5/2015
//Version: 1.0
//--------------------------------------------------
//The function Tower, which is the recursive function that calls itself with altered arguments indicating what disk needs to go where with the assistance of another tower
void Tower (int n, char BEG, char END, char AUX)
{
    if (n==1)
    {
        cout << "Move disk " << n << " from " << BEG << " to " << END << endl;
    }
    else
    {
        //Move n-1 disks from peg BEG to peg AUX
        Tower (n-1, BEG, AUX, END);
        cout << "Move disk " << n <<  " from " << BEG << " to " << END << endl;
        //Move n-1 disks from peg AUX to peg END
        Tower (n-1, AUX, END, BEG);
    }
}
//--------------------------------------------------
int main()
{
    //Main Function
    //Input parameters: User inputs the number of disks on stack A that needs to be moved to stack C
    //Output parameters: The moves that are needed to perform this operation are printed out. Also the runtime of the application.
    int disks;
    double time;
    clock_t startTime, endTime;
    cout << "Enter the number of disks: ";
    cin >> disks;
    startTime = clock();
    Tower(disks,'A','C','B');
    endTime = clock();
    time = (endTime-startTime)/double(CLOCKS_PER_SEC);
    cout << fixed << setprecision(3) << "The execution time of this program was " << time << " seconds" << endl;
    return 0;
}
