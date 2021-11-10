#include <iostream>
#include <string>
using namespace std;
typedef struct listNode listPointer;
typedef struct listNode
{
    int data;
    listPointer *link;
} listPointer;

listPointer *Traversal(listPointer *ptr)
{
    //cout << "ptr: " << ptr << endl;
    listPointer *current = ptr;
    while (current->link)
    {
        //cout << "Current: data[" << current->data << "] , link[" << current->link << "]" << endl;
        current = current->link;
    }
    //cout << "Current: data[" << current->data << "] , link[" << current->link << "]" << endl;
    return current;
}

listPointer *IndexSearch(listPointer *ptr, int index)
{
    //cout << "ptr: " << ptr << endl;
    listPointer *current = ptr;
    if (current->link)
    {
        for (int i = 0; i <= index - 1; i++)
        {
            current = current->link;
        }
    }
    return current;
}

void Display(listPointer *ptr)
{
    listPointer *current = ptr;
    while (current->link)
    {
        current = current->link;
        cout << current->data << "-->";
    }
    cout << "null" << endl;
    return;
}

void addBack(listPointer *ptr, listNode *node)
{
    listPointer *listEnd;
    listEnd = Traversal(ptr);
    listEnd->link = node;
    return;
}

void addFront(listPointer *ptr, listNode *node)
{
    node->link = ptr->link;
    ptr->link = node;
    return;
}
void addIndex(listPointer *ptr, listNode *node, int insertIndex)
{
    listPointer *listIndex;
    listIndex = IndexSearch(ptr, insertIndex);
    node->link = listIndex->link;
    listIndex->link = node;
    return;
}
void deleteIndex(listPointer *ptr, int deletedIndex)
{
    listPointer *listIndex;
    listIndex = IndexSearch(ptr, deletedIndex);
    listIndex->link = (listIndex->link)->link;
    return;
}

int main()
{
    int space = 1000;
    listPointer *ptr;
    ptr = new listPointer;
    ptr->link = NULL;
    string command[space];

    for (int i = 0; i < space; i++)
    {
        cin >> command[i];
        if (command[i] == "exit")
        {
            break;
        }
    }
    for (int i = 0; i < space; i += 2)
    {
        if (command[i] == "addBack")
        {
            listNode *node = new listNode;
            node->data = stoi(command[i + 1]);
            node->link = NULL;
            addBack(ptr, node);
        }
        else if (command[i] == "addFront")
        {
            listNode *node = new listNode;
            node->data = stoi(command[i + 1]);
            addFront(ptr, node);
        }
        else if (command[i] == "addIndex")
        {
            int insertIndex = stoi(command[i + 1]);
            listNode *node = new listNode;
            node->data = stoi(command[i + 2]);
            addIndex(ptr, node, insertIndex);
            i++;
        }
        else if (command[i] == "deleteIndex")
        {
            int deletedIndex = stoi(command[i + 1]);
            deleteIndex(ptr, deletedIndex);
        }
        else if (command[i] == "exit")
        {
            break;
        }
    }
    Display(ptr);

    //delete ptr;
    return 0;
}