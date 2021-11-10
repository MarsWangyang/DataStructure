#include <iostream>
#include <string>
using namespace std;

typedef struct listNode listPointer;
typedef struct listNode
{
    int data;
    listPointer *link;
} listPointer;

int main()
{
    listPointer *ptr;
    listPointer *ptr2;
    ptr = new listPointer[10];
    ptr2 = new listPointer[10];
    cout << ptr << endl;
    cout << ptr2 << endl;
    ptr2->link = ptr;
    cout << ptr2->link << endl;

    delete[] ptr;
    delete[] ptr2;
}