#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	//now the clock will be used to produce a better random number
	cout << srand(time(NULL)) << endl;
}
