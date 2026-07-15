// @author Soumya
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS Traversal
// Time: O(V + E) | Space: O(V) for vis[] + queue
vector<int> bfs_traversal(int v, vector<vector<int>> &adj)
{
    vector<int> bfs;
    vector<int> vis(v, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
    }

    return bfs;
}

// DFS Recursive Function
void dfs(vector<int> &dfs_store, vector<int> &vis, vector<vector<int>> &adj, int node)
{
    dfs_store.push_back(node);
    vis[node] = 1;

    for (auto it : adj[node])
        if (vis[it] == 0)
            dfs(dfs_store, vis, adj, it);
}

// DFS Traversal
// Time: O(V + E) | Space: O(V) for vis[] + recursion stack
vector<int> dfs_traversal(int v, vector<vector<int>> &adj)
{
    // Code here
    vector<int> dfs_store;
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
        if (vis[i] == 0)
            dfs(dfs_store, vis, adj, i);

    return dfs_store;
}

int main()
{
    /* sample input:
       7 7
       0 1
       0 2
       1 3
       1 4
       3 4
       2 5
       2 6

       graph (note the 1-3-4 triangle):
             0
            / \
           1   2
          /|   |\
         3-4   5 6
    */
    int n, m, i;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (i = 0; i < n; i++)
    {
        cout << i << "-->   ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    for (auto i : dfs_traversal(n, adj))
        cout << i << " ";

    return 0;
}
