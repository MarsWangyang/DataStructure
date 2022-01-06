#include <iostream>
#include <queue>
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

void levelOrder(NodePtr *root)
{
    int front = 0, rear = 0;
    NodePtr *current = root;
    queue<NodePtr *> q;
    if (!current)
    {
        return;
    }
    q.push(current);
    for (;;)
    {
        current = q.front();
        // cout << "current: " << current << endl;
        if (current)
        {
            cout << current->data << " ";
            if (current->leftNode)
            {
                q.push(current->leftNode);
            }
            if (current->rightNode)
            {
                q.push(current->rightNode);
            }
            q.pop();
        }
        else
            break;
    }
}

void InorderTraversalRecursive(NodePtr *root)
{
    NodePtr *current = root;
    if (current)
    {
        InorderTraversalRecursive(current->leftNode);
        cout << current->data << " ";
        InorderTraversalRecursive(current->rightNode);
    }
}

int main()
{
    int temp;
    vector<int> v;
    while (cin >> temp)
    {
        v.push_back(temp);
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    NodePtr *root = new Node;
    root->data = v.at(0);
    // root->leftNode = NULL;
    // root->rightNode = NULL;
    root->parent = NULL;
    NodePtr *current = root;
    queue<NodePtr *> q;

    for (int i = 0; i < v.size(); i++)
    {
        int leftLoc = 2 * i + 1;
        int rightLoc = 2 * i + 2;
        NodePtr *newLeftNode = new NodePtr;
        NodePtr *newRightNode = new NodePtr;
        newLeftNode->parent = current;
        newRightNode->parent = current;

        if (leftLoc < v.size() && rightLoc < v.size())
        {

            newLeftNode->data = v.at(leftLoc);
            newRightNode->data = v.at(rightLoc);

            current->leftNode = newLeftNode;
            current->rightNode = newRightNode;
            q.push(newLeftNode);
            q.push(newRightNode);
        }
        else if (leftLoc >= v.size())
        {
            newLeftNode->data = -1;
            newRightNode->data = -1;

            current->leftNode = NULL;
            current->rightNode = NULL;
        }
        else if (leftLoc < v.size() && rightLoc >= v.size())
        {
            newLeftNode->data = v.at(leftLoc);
            newRightNode->data = -1;

            current->leftNode = newLeftNode;
            current->rightNode = NULL;
            q.push(newLeftNode);
        }

        if (q.front())
        {
            current = q.front();
            q.pop();
        }
    }
    levelOrder(root);
    return 0;
}