#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct HeapNode
{
    string workContent;
    int priorityValue;
    HeapNode() : workContent("zeroLocation"), priorityValue(0){};
    HeapNode(string workContent, int priorityValue) : workContent(workContent), priorityValue(priorityValue) {}
};

void Swap(struct HeapNode &p1, struct HeapNode &p2)
{
    struct HeapNode temp = p1;
    p1 = p2;
    p2 = temp;
}

void MaxHeapify(vector<HeapNode> *heap, int node, int length)
{
    int left = 2 * node,
        right = 2 * node + 1,
        maximun;
    if (left <= length)
    {
        if (left < heap->size() && node < heap->size())
        {
            cout << "left: " << left << " " << node << endl;
            if (heap->at(left).priorityValue > heap->at(node).priorityValue)
            {
                cout << "left: " << left << " node: " << node << endl;
                maximun = left;
            }
        }
    }
    else
        maximun = node;

    if (right <= length)
    {
        if (right < heap->size() && maximun < heap->size())
        {
            cout << "right: " << right << " " << maximun << endl;

            if (heap->at(right).priorityValue > heap->at(maximun).priorityValue)
            {
                cout << "right: " << right << " maximun: " << maximun << endl;
                maximun = right;
            }
        }
    }

    if (maximun != node)
    {
        cout << "heap->(maxiumun): " << heap->at(maximun).workContent << " " << heap->at(maximun).priorityValue << " heap->at(node):" << heap->at(node).workContent << " " << heap->at(node).priorityValue << endl;
        Swap(heap->at(maximun), heap->at(node));
        MaxHeapify(heap, maximun, length);
    }
}

bool IsHeapEmpty(vector<HeapNode> *heap) { return (heap->size() < 1); }

string ExtractMax(vector<HeapNode> *heap)
{
    if (IsHeapEmpty(heap))
    {
        cout << "error: empty\n";
        exit(-1);
    }
    string max = heap->at(1).workContent;
    cout << max << endl;
    heap->at(1) = heap->at(heap->size() - 1);
    heap->erase(heap->begin() + (heap->size()) - 1);
    MaxHeapify(heap, 1, (int)heap->size());

    return max; // 回傳heap中
}

int main()
{
    int cnt;
    string workContent;
    int priorityValue;
    vector<HeapNode> heap;
    cin >> cnt;
    heap.resize(1);
    for (int i = 1; i <= cnt; i++)
    {
        cin >> workContent >> priorityValue;
        HeapNode node = HeapNode(workContent, priorityValue);
        heap.push_back(node);
    }

    for (int i = (int)heap.size() / 2; i >= 1; i--)
    {
        cout << "i: " << i << endl;
        MaxHeapify(&heap, i, (int)heap.size() - 1); // length要減一, 因為heap從從1開始存放資料
    }
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i].workContent << " " << heap[i].priorityValue << endl;
    }
    // cout << "First three things to do:" << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     ExtractMax(&heap);
    // }
    return 0;
}