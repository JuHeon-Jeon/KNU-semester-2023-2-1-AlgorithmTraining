#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct edge
{
    int u, v, w;
} edge;

struct edge_compare
{
    bool operator()(edge e1, edge e2)
    {
        if (e1.w > e2.w)
            return true;
        else
            return false;
    }
};

typedef vector<edge> setOfEdges;
typedef priority_queue<edge, vector<edge>, edge_compare> PirorityQueue;

setOfEdges E, F;
vector<int> dset;

void kruskal(int n, int m);

int main(void)
{
    int n, m;

    cin >> n >> m;
    E.resize(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> E[i].u;
        cin >> E[i].v;
        cin >> E[i].w;
    }

}

void kruskal(int n, int m)
{
    int p, q;
    edge e;
    PirorityQueue PQ;

    dset.resize(n + 1);
    for (int i = 1; i <= n; i++)
        dset[i] = i;
}