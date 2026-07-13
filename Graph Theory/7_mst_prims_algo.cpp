// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

int primsAlgo(int V, vector<vector<int>> &edges)
{
    // code here
    vector<vector<pair<int, int>>> adj(V);

    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    vector<int> vis(V, 0);
    vector<pair<int, int>> minWays;
    int pathSum = 0;
    minHeap.push({0, 0, -1});

    while (!minHeap.empty())
    {
        // {wt, node, parent}
        int wt = minHeap.top()[0];
        int node = minHeap.top()[1];
        int parent = minHeap.top()[2];
        minHeap.pop();

        if (vis[node])
            continue;

        vis[node] = 1;
        minWays.push_back({parent, node});
        pathSum += wt;

        for (auto it : adj[node])
            if (!vis[it.first])
                minHeap.push({it.second, it.first, node});
    }

    return pathSum;
}

int main()
{
    vector<vector<int>> edges{{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 1}, {2, 3, 5}, {3, 4, 3}};
    int V = 5;
    /* graph (edge weights shown):
            4         1
        0 ------ 1 ------ 3 ------ 4
         \       |        /   3
          \1     |2      /5
           \      |     /
            ----- 2 ----
       MST picks edges 0-2(1), 1-3(1), 1-2(2), 3-4(3) => total weight 7
    */

    cout << primsAlgo(V, edges) << endl;

    return 0;
}