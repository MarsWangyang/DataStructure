#include <iostream>
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
        cout << "Traversal: " << current->data << " " << current->link << endl;
        current = current->link;
    }
    //cout << "*current: " << *current << endl;
    return current;
}

int main()
{
    listPointer *traversal;
    listPointer *ptr;
    listPointer *arr1;
    listPointer *arr2;
    //listPointer *arr3;
    //listPointer *arr4;
    ptr = new listPointer;
    ptr->link = NULL;
    arr1 = new listPointer;
    arr2 = new listPointer;
    //arr3 = new listPointer;
    //arr4 = new listPointer;
    ptr->link = arr1;
    arr1->data = 1;
    arr1->link = arr2;
    arr2->data = 2;
    arr2->link = NULL;
    cout << arr2 << endl;
    cout << arr2->link << endl;
    traversal = Traversal(ptr);
    cout << traversal << endl;
    cout << traversal->data << endl;
    cout << traversal->link << endl;
    //delete traversal;
    delete ptr;
    delete arr1;
    delete arr2;

    listNode test;
    test.data = 2;
    test.link = NULL;
    cout << &test << endl;
    //delete arr3;
    //delete arr4;

    return 0;
}