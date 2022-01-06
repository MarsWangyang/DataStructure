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
    listPointer *current = ptr;
    while (current->link)
    {
        current = current->link;
    }

    return current;
}

listPointer *IndexSearch(string func, listPointer *ptr, int index)
{
    listPointer *current = ptr;
    int cnt = 0;

    while (current->link)
    {
        if (cnt == index)
        {
            return current;
        }
        else
        {
            current = current->link;
            cnt++;
        }
    }
    if (cnt != index)
    {
        return NULL;
    }
    //這邊要特別注意deleteIndex 0 exit 不能return current，否則會吃到錯誤的記憶體
    if (func != "deleteIndex")
    {
        return current;
    }
    return NULL;
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