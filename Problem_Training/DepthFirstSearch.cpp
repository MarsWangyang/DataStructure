#include <iostream>
#include <stack>
using namespace std;
/*
    DFS: use stack, preorder traversal
    BFS: use queue, level order traversal
*/
typedef struct Node NodePtr;
typedef struct Node
{
    int vertex;
    NodePtr *link;
} NodePtr;

void dfs(int v)
{
    Node *graph;
    graph = new Node[10];
    bool visited[10];
    NodePtr *w;
    visited[v] = true;
    cout << v << " ";
    for (w = graph + v; w; w = w->link)
    {
        if (!visited[w->vertex])
        {
            dfs(w->vertex);
        }
    }
    return;
}

void bfs(int v)
{
    NodePtr *w;
    NodePtr *front, *rear;
    bool visited[101];
    NodePtr *graph;
    graph = new NodePtr[101];
    front = rear = NULL;
    cout << v << " ";
    visited[v] = true;
    // addq(front, rear, v);
    while (front)
    {
        // v = deleteq(&front);
        for (w = graph + v; w; w = w->link)
        {
            cout << w->vertex << " ";
            // addq(front, rear, w->vertex);
            visited[w->vertex] = true;
        }
    }
}

void connected()
{
    int n;
    bool visited[101];
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cout << "\n";
        }
    }
}

int main()
{

    return 0;
}