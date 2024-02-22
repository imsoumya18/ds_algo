// @author Soumya
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS Traversal
vector<int> bfs_traversal(int v, vector<int> adj[])
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
void dfs(vector<int> &dfs_store, vector<int> &vis, vector<int> adj[], int node)
{
    dfs_store.push_back(node);
    vis[node] = 1;

    for (auto it : adj[node])
        if (vis[it] == 0)
            dfs(dfs_store, vis, adj, it);
}

// DFS Traversal
vector<int> dfs_traversal(int v, vector<int> adj[])
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
    int n, m, i;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (i = 1; i <= n; i++)
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
