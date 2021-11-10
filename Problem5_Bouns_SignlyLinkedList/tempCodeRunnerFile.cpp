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
        //cout << "Current in: data[" << current->data << "] , link[" << current->link << "]" << endl;
    }

    return current;
}

listPointer *IndexSearch(string func, listPointer *ptr, int index)
{
    listPointer *current = ptr;
    listPointer *temp;
    int cnt = 0;

    while (current->link)
    {
        if (cnt == index)
        {

            return current;
        }
        else
        {
            temp = current;
            current = current->link;
            cnt++;
        }
    }

    return NULL;

    // if (func == "deleteIndex")
    // {
    //     return temp;
    // }
    // else
    // {
    //     return current;
    // }

    // if (current->link)
    // {

    //     for (int i = 0; i <= index - 1; i++)
    //     {

    //         cout << "current: " << current->data << " " << current->link << endl;

    //         current = current->link;

    //         cout << "current->link: " << current->data << " " << current->link << endl;
    //     }
    // }
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
    listIndex = IndexSearch("addIndex", ptr, insertIndex);
    if (listIndex)
    {
        node->link = listIndex->link;
        listIndex->link = node;
    }
    return;
}
void deleteIndex(listPointer *ptr, int deletedIndex)
{
    listPointer *listIndex;
    listIndex = IndexSearch("deleteIndex", ptr, deletedIndex);
    if (listIndex)
    {
        listIndex->link = (listIndex->link)->link;
    }
    return;
}

int main()
{
    int space = 1000;
    string inputCommand;
    string command[space];
    bool EXIT = false;
    int cnt = 0;
    listPointer *ptr;
    ptr = new listPointer;
    ptr->data = 0;
    ptr->link = NULL;

    while (EXIT == false)
    {
        cin >> inputCommand;
        command[cnt] = inputCommand;
        if (inputCommand == "exit")
        {
            EXIT = true;
        }
        cnt++;
    }
    EXIT = false;
    int i = 0;
    while (EXIT == false)
    //for (int i = 0; i < space; i += 2)
    {
        if (command[i] == "addBack")
        {
            listNode *node = new listNode;
            node->data = stoi(command[i + 1]);
            node->link = NULL;
            addBack(ptr, node);
            i += 2;
        }
        else if (command[i] == "addFront")
        {
            listNode *node = new listNode;
            node->data = stoi(command[i + 1]);
            addFront(ptr, node);
            i += 2;
        }
        else if (command[i] == "addIndex")
        {

            int insertIndex = stoi(command[i + 1]);
            listNode *node = new listNode;
            node->data = stoi(command[i + 2]);
            addIndex(ptr, node, insertIndex);
            i += 2;
            i++;
        }
        else if (command[i] == "deleteIndex")
        {
            int deletedIndex = stoi(command[i + 1]);
            deleteIndex(ptr, deletedIndex);
            i += 2;
        }
        else if (command[i] == "exit")
        {

            Display(ptr);
            EXIT = true;
        }
    }

    delete ptr;
    return 0;
}