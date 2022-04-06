#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node NodePtr;
typedef struct Node
{
    NodePtr *leftNode;
    NodePtr *rightNode;
    NodePtr *parent;
    int data;
} NodePtr;

void InorderTraversal(NodePtr *root)
{
    NodePtr *current = root;
    stack<NodePtr *> nodeStack;
    for (;;)
    {
        for (; current; current = current->leftNode)
        {
            nodeStack.push(current);
        }
        if (nodeStack.size() != 0)
        {
            current = nodeStack.top();
        }
        else
        {
            break;
        }
        if (!current)
        {
            break;
        }

        cout << current->data << " ";
        nodeStack.pop();
        current = current->rightNode;
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

void PostorderTraversalRecursive(NodePtr *root)
{
    NodePtr *current = root;
    if (current)
    {
        PostorderTraversalRecursive(current->leftNode);
        PostorderTraversalRecursive(current->rightNode);
        cout << current->data << " ";
    }
}

void PreorderTraversalRecursive(NodePtr *root)
{
    NodePtr *current = root;
    if (current)
    {
        cout << current->data << " ";
        PreorderTraversalRecursive(current->leftNode);
        PreorderTraversalRecursive(current->rightNode);
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

    Node *root = new NodePtr;
    root->parent = NULL;
    root->data = v.at(0);
    NodePtr *currentNode = root;
    queue<NodePtr *> q;

    int i = 0;
    while (i < v.size())
    {
        int leftLoc = 2 * i + 1;
        int rightLoc = 2 * i + 2;
        if (leftLoc < v.size() && rightLoc < v.size())
        {
            NodePtr *newLeftNode = new NodePtr;
            NodePtr *newRightNode = new NodePtr;

            newLeftNode->data = v.at(leftLoc);
            newRightNode->data = v.at(rightLoc);

            newLeftNode->parent = currentNode;
            newRightNode->parent = currentNode;

            currentNode->leftNode = newLeftNode;
            currentNode->rightNode = newRightNode;
            q.push(newLeftNode);
            q.push(newRightNode);
        }
        else if (leftLoc >= v.size())
        {
            NodePtr *newLeftNode = new NodePtr;
            NodePtr *newRightNode = new NodePtr;

            newLeftNode->data = -1;
            newRightNode->data = -1;

            newLeftNode->parent = currentNode;
            newRightNode->parent = currentNode;

            currentNode->leftNode = NULL;
            currentNode->rightNode = NULL;
        }
        else if (leftLoc < v.size() && rightLoc >= v.size())
        {
            NodePtr *newLeftNode = new NodePtr;
            NodePtr *newRightNode = new NodePtr;

            newLeftNode->data = v.at(leftLoc);
            newRightNode->data = -1;

            newLeftNode->parent = currentNode;
            newRightNode->parent = currentNode;

            currentNode->leftNode = newLeftNode;
            currentNode->rightNode = NULL;
            q.push(newLeftNode);
        }

        if (q.front())
        {
            currentNode = q.front();
            q.pop();
        }
        i++;
    }

    NodePtr *current = root;
    // InorderTraversal(root);
    InorderTraversalRecursive(root);
    cout << endl;
    PreorderTraversalRecursive(root);
    cout << endl;
    PostorderTraversalRecursive(root);
    return 0;
}