// @author Soumya
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS Traversal
vector<int> bfs_traversal(int v, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            // bfs of the node
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto j : adj[node])
                    if (!vis[j])
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
            }
        }
    }

    return bfs;
}

// DFS Recursive Function
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs_store)
{
    dfs_store.push_back(node);
    vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, vis, adj, dfs_store);
}

// DFS Traversal
vector<int> dfs_traversal(int v, vector<int> adj[])
{
    vector<int> dfs_store;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
        if (!vis[i])
            dfs(i, vis, adj, dfs_store);

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
