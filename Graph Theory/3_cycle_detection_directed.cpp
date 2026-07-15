// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfs_vis)
{
    vis[node] = 1;
    dfs_vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it])
        {
            if (dfs(it, adj, vis, dfs_vis))
                return true;
        }
        else if (dfs_vis[it] == 1)
            return true;

    dfs_vis[node] = 0;

    return false;
}

// Time: O(V + E) | Space: O(V) for vis[] + dfs_vis[] + recursion stack
bool isCycle_dfs(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0), dfs_vis(V, 0);

    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i, adj, vis, dfs_vis))
                return true;

    return false;
}

// Time: O(V + E) | Space: O(V) for indegree[] + queue
bool isCycle_bfs(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);

    for (auto it : adj)
        for (auto node : it)
            indegree[node]++;

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

    return vct.size() != V;
}

int main()
{
    /* sample input (has a cycle: 1 -> 2 -> 3 -> 1):
       4 4
       0 1
       1 2
       2 3
       3 1

       graph:
         0 --> 1 --> 2 --> 3
               ^           |
               +-----------+
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

    if (isCycle_dfs(n, adj))
        cout << "Cycle is there" << endl;
    else
        cout << "Cycle isn't there" << endl;

    return 0;
}