#include <iostream>
#include <stack>

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
    while ((n != 1) && (node.key > heap[n / 2].key))
    {
        heap[n] = heap[n / 2];
        n /= 2;
    }
    heap[n] = node;
}

HeapNode deleteMaxHeap(HeapNode heap[], int n)
{
    // para n: the size of the heap
    int parent = 1, child = 2;
    HeapNode item = heap[1];
    HeapNode temp = heap[n];
    while (child <= n)
    {
        if ((child < n) && (heap[child].key < heap[child + 1].key))
        {
            child++;
        }
        if (temp.key >= heap[child].key)
        {
            break;
        }
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
    heap[0] = HeapNode(); //對第一個空間放入一個沒用的Node, 後續在Parent以及Child計算上會比較方便
    for (int i = 1; i <= cnt; i++)
    {
        cin >> currentWork >> currentKey;
        HeapNode currentNode = HeapNode(currentWork, currentKey);
        insertMaxHeap(heap, currentNode, i);
    }
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

    return 0;
}