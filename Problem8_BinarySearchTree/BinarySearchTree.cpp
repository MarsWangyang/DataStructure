#include <iostream>
#include <vector>
using namespace std;
typedef struct TreeNode TreeNodePtr;
typedef struct TreeNode
{

    TreeNodePtr *leftChild;
    TreeNodePtr *rightChild;
    TreeNodePtr *parent;
    int data;
} TreeNodePtr;

void AddNode(TreeNodePtr *root, int nodeData)
{
    TreeNode *currentRoot = root;
    TreeNode *addNode = new TreeNode;
    addNode->data = nodeData;
    addNode->leftChild = NULL;
    addNode->rightChild = NULL;
    while (true)
    {
        if (nodeData < currentRoot->data)
        {
            if (currentRoot->leftChild)
            {
                currentRoot = currentRoot->leftChild;
            }
            else
            {
                addNode->parent = currentRoot;
                currentRoot->leftChild = addNode;
                break;
            }
        }
        else
        {
            if (currentRoot->rightChild)
            {
                currentRoot = currentRoot->rightChild;
            }
            else
            {
                addNode->parent = currentRoot;
                currentRoot->rightChild = addNode;
                break;
            }
        }
    }
}
bool check = false;
int goalValue = 0;

void findLeaf(TreeNodePtr *root)
{
    if (!root)
    {
        return;
    }
    if (!root->leftChild && !root->rightChild)
    {
        int value = 0;
        for (; root;)
        {
            value += root->data;
            root = root->parent;
        }
        if (value == goalValue)
        {
            check = true;
            return;
        }
        return;
    }

    // if left child exists, check for leaf
    // recursively
    if (root->leftChild)
    {
        findLeaf(root->leftChild);
    }

    // if right child exists, check for leaf
    // recursively
    if (root->rightChild)
    {
        findLeaf(root->rightChild);
    }
}

int main()
{
    int cnt, first;
    cin >> cnt >> first;
    TreeNodePtr *root = new TreeNodePtr;
    root->leftChild = NULL;
    root->rightChild = NULL;
    root->parent = NULL;
    root->data = first;

    for (int i = 1; i < cnt; i++)
    {
        int temp;
        cin >> temp;
        AddNode(root, temp);
    }
    int goal;
    cin >> goal;
    goalValue = goal;

    findLeaf(root);
    if (check)
    {
        cout << "There exit at least one path in binary search tree." << endl;
    }
    else
    {
        cout << "There have no path in binary search tree." << endl;
    }
    // cout << "Root->data: " << root->data << endl;
    // cout << "1: " << root->leftChild->data << endl;
    // cout << "2: " << root->leftChild->rightChild->data << endl;
    // cout << "6: " << root->rightChild->data << endl;
    // cout << "5: " << root->rightChild->leftChild->data << endl;
    return 0;
}