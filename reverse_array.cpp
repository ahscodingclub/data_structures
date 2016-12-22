#include <iostream>

using namespace std;

void ReverseArray(int arr[], int i, int j)
{
    int temp = 0;
    if(i<j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        ReverseArray(arr, (i+1), (j-1));
    }
    return;
}
int main()
{
    int i = 0;
    int j = 4;
    int result[] = {1, 2, 3, 4, 5};
    ReverseArray(result, i, j);
    for(i=0;i<5;i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
