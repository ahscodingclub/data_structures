#include <iostream>

using namespace std;

//==================================================
//Title: Assignment 5, Hash Data Structure
//Algorithm: N/A
//Pre-conditions:
//Post-conditions: A Hash Table is dynamically created/changed by using menu options with the hash functions that the user selects at runtime.
//Exceptions: Non-Integer validation is not performed
//Programmer: Jake Sauter
//Date: 9/29/2015
//Version: 1.0
//--------------------------------------------------
struct Node
{
    int data;
    Node* next;
};
//--------------------------------------------------
class HashDataStructure
{
    public:
        HashDataStructure();
        ~HashDataStructure();
        void insertElement(int n);
        bool isElement(int n);
        void deleteElement(int n);
    private:
        Node* hashTable[7];
        int hashFunction(int n);
};
//--------------------------------------------------
HashDataStructure::HashDataStructure()
{
    Node* node = new Node;
    node->data = 0;
    node->next = NULL;
    for(int i=0;i<7;i++)
    {
        node->data = -1;
        hashTable[i] = node;
    }
}
//--------------------------------------------------

int HashDataStructure::hashFunction(int element)
{
    return (element%7);
}
//--------------------------------------------------
void HashDataStructure::insertElement(int n)
{
    Node* node = new Node;
    node->data = 0;
    node->next = NULL;
    int index = 0;
    index = hashFunction(n);
    node->data = n;
    //if the value at the current index is -1 then there is not an element there and we can
    if(hashTable[index]->data == -1)
    {
        hashTable[index] = node;
    }
    //if the value is not -1, then we have collided and now we need to deal with it
    else
    {
        Node* travNode = hashTable[index];
        while(travNode->next!=NULL)
        {
            travNode = travNode->next;
        }
        travNode->next = node;
    }

}
//--------------------------------------------------
bool HashDataStructure::isElement(int n)
{
    Node* node = new Node;
    node->data = 0;
    node->next = NULL;
    int index;
    bool found = false, breakVar = false;
    index = hashFunction(n);
    node = hashTable[index];
    //program getting stuck in this loop
    while(!breakVar)
    {
        if(node->data == n)
        {
            breakVar = true;
            found = true;
        }
        else
        {
            if(node->next != NULL)
            {
                node = node->next;
            }
            else
            {
                breakVar = true;
                found = false;
            }
        }
    }
    return found;


}
//--------------------------------------------------
void HashDataStructure::deleteElement(int n)
{
    Node* node = new Node;
    node->data = 0;
    node->next = NULL;
    int index;
    bool breakVar = false;
    index = hashFunction(n);
    node = hashTable[index];
    while(!breakVar)
    {
        if(node->data == n)
        {
            breakVar = true;
            //to make sure that we don't forget about the node after the one we delete, we can just set the
            //array index to the next node
            if(node->next!=NULL)
            {
                hashTable[index] = node->next;
            }
            else
            {
                node->data = -1;
            }
        }
        else
        {
            if(node->next != NULL)
            {
                node = node->next;
            }
            else
            {
                breakVar = true;
            }
        }
    }
}
//--------------------------------------------------
HashDataStructure::~HashDataStructure()
{
    delete hashTable;
}
//--------------------------------------------------
void printMenu()
{
    cout << "1. Add element to table" << endl;
    cout << "2. Check if element is in table" << endl;
    cout << "3. Delete element from table" << endl;
    cout << "any other integer to break" << endl;
    cout << "Please enter your choice: ";
}
//--------------------------------------------------
int main()
{
    int choice = 0, n;
    bool exists;
    HashDataStructure hds;
    do
    {
        do
        {
            if(choice < 0 || choice > 4)
            {
                cout << "\nSorry but that is not a valid choice, please provide a valid choice" << endl << endl;
            }
            printMenu();
            cin >> choice;
            cout << endl;
        }while(choice < 0 || choice > 4);

        cout << "Please enter the value that you wish to do so with: ";
        cin >> n;
        cout << endl;
        switch(choice)
        {
            case 1: hds.insertElement(n);
                break;
            case 2: exists = hds.isElement(n);
                    if(exists)
                    {
                        cout << "\nThis element is in the hash table" << endl << endl;
                    }
                    else
                    {
                        cout << "\nThis element is not in the hash table" << endl << endl;
                    }
                break;
            case 3: hds.deleteElement(n);
                break;
        }
    }while(choice > 0 && choice < 4);
    return 0;
}
