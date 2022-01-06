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

void test(vector<HeapNode> heap)
{
    cout << "heap: " << heap[1].priorityValue << endl;

    // cout << "heap: " << (heap + 2) << endl;
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
    test(heap);
    // cout << heap[1].priorityValue << endl;
}