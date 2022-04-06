#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node NodePtr;
typedef struct Node
{
    NodePtr *leftNode;
    NodePtr *rightNode;
    NodePtr *parent;
    int data;
} NodePtr;

Node *copy(NodePtr *root)
{
    NodePtr *temp;
    if (root)
    {
        temp = new NodePtr;
        temp->leftNode = copy(root->leftNode);
        temp->rightNode = copy(root->rightNode);
        temp->data = root->data;
        return temp;
    }
    return NULL;
}

int equal(NodePtr *firstTree, NodePtr *secondTree)
{
    return ((!firstTree && !secondTree) ||
            (firstTree && secondTree && firstTree->data == secondTree->data) &&
                equal(firstTree->leftNode, secondTree->leftNode) &&
                equal(firstTree->rightNode, secondTree->rightNode));
}

int main()
{
    int temp;
    vector<int> v;
    NodePtr *root = new NodePtr;

    while (cin >> temp)
    {
        v.push_back(temp);
        if (cin.peek() == '\n')
        {
            break;
        }
    }

    root->data = v.at(0);
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

    return 0;
}