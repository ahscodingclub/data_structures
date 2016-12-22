#include <iostream>

using namespace std;

//==================================================
//Title: Assignment 5
//Algorithm: N/A
//Pre-conditions:
//Post-conditions: A Binary Search Tree is dynamically allocated by using menu options with the bst functions that the user selects at runtime.
//Exceptions: Non-Integer validation is not performed
//Programmer: Jake Sauter
//Date: 9/29/2015
//Version: 1.0
//--------------------------------------------------

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};
//--------------------------------------------------
class TreeType
{
    public:
        TreeType();
        bool isEmpty() const;//const means that it cannot edit our private members
        bool isFull();
        void numberOfNodes();
        void insertItem(int item);
        void deleteItem(int item);
        void retrieveItem(int& item, bool& found);
        void printTree() const;
        ~TreeType();
    private:
        TreeNode* root;
};
//--------------------------------------------------
void InsertHelper(TreeNode*& ptr, int item);
void PrintHelper(TreeNode* ptr);

void RetrieveHelper(TreeNode* ptr, int&, bool& found);

void DestroyHelper(TreeNode* ptr);

TreeNode* DeleteHelper(TreeNode* root, int item);
//--------------------------------------------------
TreeType::TreeType()
{
    root = NULL;
}
//--------------------------------------------------
bool TreeType::isEmpty() const
{
    return (root==NULL);
}
//--------------------------------------------------
void TreeType:: retrieveItem(int& item, bool& found)
{
    RetrieveHelper(root, item, found);
}
//--------------------------------------------------
void RetrieveHelper(TreeNode* ptr, int& item, bool& found)
{

    if(ptr == NULL)
    {
        found = false;
    }
    else if(item < ptr->data)
    {
        RetrieveHelper(ptr->left, item, found);
    }
    else if(item > ptr->data)
    {
        RetrieveHelper(ptr->right, item, found);
    }
    else
    {
        item = ptr->data;
        found = true;
    }
}
//--------------------------------------------------
void TreeType::insertItem(int item)
{
    InsertHelper(root, item);
}
//--------------------------------------------------
void InsertHelper(TreeNode*& ptr, int item)
{
    if(ptr == NULL)
    {
        ptr = new TreeNode;
        ptr->right=NULL;
        ptr->left=NULL;
        ptr->data=item;
    }
    else if(item < ptr->data)
    {
        InsertHelper(ptr->left, item);
    }
    else if(item > ptr->data)
    {
        InsertHelper(ptr->right, item);
    }
}
//--------------------------------------------------
void TreeType::printTree() const
{
    PrintHelper(root);
}
//--------------------------------------------------
void PrintHelper(TreeNode* ptr)
{
    if(ptr!=NULL)
    {
        PrintHelper(ptr->left); //print left subtree
        cout << ptr->data << " ";
        PrintHelper(ptr->right); //print right subtree
    }
}
//--------------------------------------------------
void TreeType::deleteItem(int item)
{
    DeleteHelper(root, item);
}
//--------------------------------------------------
int FindMin(TreeNode* root)
{
    if(root == NULL)
    {
        cout << "Error the tree is empty" << endl;
        return -1;
    }
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;
}
TreeNode* DeleteHelper(TreeNode *root, int data)
{
    //searching for the node
    if(root==NULL)
    {
        return root;
    }
    else if(data < root->data)
    {
        root->left = DeleteHelper(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = DeleteHelper(root->right, data);
    }
    else//the node is now found
    {
        //case 1: no child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //case 2: One Child
        else if(root->left == NULL)
        {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: 2 children
        else
        {
            TreeNode* temp = new TreeNode();
            temp->data = FindMin(root->right);
            root->data = temp->data;
            root->right = DeleteHelper(root->right, temp->data);
        }
    }
    return root;
}
//--------------------------------------------------
void counterHelper(TreeNode* ptr, int&c)
{
    if(ptr!=NULL)
    {
        counterHelper(ptr->left, c); //print left subtree
        c++;
        counterHelper(ptr->right, c); //print right subtree
    }
}
//--------------------------------------------------
void TreeType::numberOfNodes()
{
    int c = 0;
    counterHelper(root, c);
    cout << "The number of node in the tree is: " << c << endl;
}
//--------------------------------------------------
TreeType::~TreeType()
{
    DestroyHelper(root);
}
//--------------------------------------------------
void DestroyHelper(TreeNode* ptr)
{
    if(ptr==NULL)
    {
        DestroyHelper(ptr->left);
        DestroyHelper(ptr->right);
        delete ptr;
    }
}
//--------------------------------------------------
void printMenu()
{
    cout << "1. Add an item" << endl;
    cout << "2. Delete an item" << endl;
    cout << "3. Retrieve an item" << endl;
    cout << "4. Print the tree" << endl;
    cout << "5. Count items in tree" << endl;
    cout << "6. End Program" << endl;
    cout << "Please enter your choice: ";
}
//--------------------------------------------------
//Main Function
//Input parameters: User inputs menu selection and any further information needed from that menu choice
//Output parameters: The result of the menu choice that the user has selected
int main()
{
    TreeType tree;
    int choice = 0;
    int item;
    bool found = false;
    do
    {
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                    cout << "Please enter the item you would like to add: ";
                    cin >> item;
                    tree.insertItem(item);
                break;
            case 2:  cout << "Please enter the item you would like to delete ";
                     cin >> item;
                     tree.deleteItem(item);
                break;
            case 3: cout << "Please enter the item you would like to retrieve: ";
                    cin >> item;
                    tree.retrieveItem(item, found);
                    cout << endl;
                    if(found)
                    {
                        cout << "This item was found" << endl;
                    }
                    else
                    {
                        cout << "This item was not found" << endl;
                    }
                break;
            case 4: cout << endl;
                    tree.printTree();
                    cout << endl;
                break;
            case 5:  tree.numberOfNodes();
                break;
        }
        cout << endl;
    }while(choice > 0 && choice < 6);
    return 0;
}
