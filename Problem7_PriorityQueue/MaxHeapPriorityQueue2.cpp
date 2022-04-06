#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct HeapNode
{
    string work;
    int key;
    HeapNode() : work("zeroWork"), key(0){};
    HeapNode(string work, int key) : work(work), key(key){};
};

void insertMaxHeap(HeapNode heap[], HeapNode node, int n)
{
    int i = n;
    while ((i != 1) && (node.key > heap[i / 2].key))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = node;
}

HeapNode deleteMaxHeap(HeapNode heap[], int n)
{
    int parent = 1, child = 2;
    HeapNode item, temp;
    item = heap[1];
    temp = heap[n];
    while (child <= n)
    {
        if ((child < n) && (heap[child].key < heap[child + 1].key))
        {
            child++;
        }
        if (temp.key >= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

int main()
{
    int cnt, currentKey;
    string currentWork;
    cin >> cnt;
    HeapNode *heap;
    heap = new HeapNode[cnt + 1];
    heap[0] = HeapNode();
    for (int i = 1; i <= cnt; i++)
    {
        cin >> currentWork >> currentKey;
        HeapNode currentNode = HeapNode(currentWork, currentKey);
        insertMaxHeap(heap, currentNode, i);
    }
    // cout << "length: " << sizeof(heap) / sizeof(*heap) << endl;
    cout << "First three things to do:" << endl;
    if (cnt < 3)
    {
        for (int i = 1; i < 3; i++)
        {
            HeapNode extractNode = deleteMaxHeap(heap, cnt + 1 - i);
            cout << extractNode.work << endl;
        }
    }
    else
    {
        for (int i = 1; i < 4; i++)
        {
            HeapNode extractNode = deleteMaxHeap(heap, cnt + 1 - i);
            cout << extractNode.work << endl;
        }
    }

    // delete heap;
    return 0;
}