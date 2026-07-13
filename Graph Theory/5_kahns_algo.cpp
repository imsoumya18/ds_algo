// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topo_sort(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);

    for (auto node : adj)
        for (auto it : node)
            indegree[it]++;

    queue<int> q;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> vct;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        vct.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return vct;
}

int main()
{
    /* sample input:
       6 6
       0 1
       0 2
       1 3
       2 3
       3 4
       3 5

       graph (a valid topo order: 0 1 2 3 4 5):
             0
            / \
           1   2
            \ /
             3
            / \
           4   5
    */
    int n, m, i;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    for (i = 0; i < n; i++)
    {
        cout << i << "-->   ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    for (auto it : topo_sort(n, adj))
        cout << it << " ";

    return 0;
}