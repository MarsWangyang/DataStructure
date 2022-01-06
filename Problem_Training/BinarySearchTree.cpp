#include <iostream>
#include <vector>
using namespace std;
typedef struct Node NodePtr;
typedef struct Node
{
    NodePtr *leftNode;
    NodePtr *rightNode;
    NodePtr *parent;
    int data;
} NodePtr;

void AddNode(NodePtr *root, int nodeData)
{
    NodePtr *current = root;
    NodePtr *addNode = new NodePtr;
    addNode->data = nodeData;
    addNode->leftNode = NULL;
    addNode->rightNode = NULL;
    while (true)
    {
        if (nodeData < current->data)
        {
            if (current->leftNode)
            {
                current = current->leftNode;
            }
            else
            {
                current->leftNode = addNode;
                addNode->parent = current;
                break;
            }
        }
        else
        {
            if (current->rightNode)
            {
                current = current->rightNode;
            }
            else
            {
                addNode->parent = current;
                current->rightNode = addNode;
                break;
            }
        }
    }
}
bool check = false;
int goalValue = 0;

void findLeaf(NodePtr *root)
{
    if (!root)
    {
        return;
    }
    if (!root->leftNode && !root->rightNode)
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

    if (root->leftNode)
    {
        findLeaf(root->leftNode);
    }

    if (root->rightNode)
    {
        findLeaf(root->rightNode);
    }
}
int main()
{
    int cnt, first;
    cin >> cnt >> first;
    NodePtr *root = new NodePtr;
    root->leftNode = NULL;
    root->rightNode = NULL;
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
        cout << "Find it" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }
    return 0;
}