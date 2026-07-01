// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

void print(vector<int> vct)
{
    for (auto i : vct)
        cout << i << " ";
    cout << endl;
}

void print(vector<vector<int>> vct)
{
    for (auto i : vct)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

bool isCycle_bfs(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);

    for (int node = 0; node < V; node++)
    {
        if (vis[node])
            continue;

        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;

        while (!q.empty())
        {
            int nd = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[nd])
                if (!vis[it])
                {
                    q.push({it, nd});
                    vis[it] = 1;
                }
                else if (it != parent)
                    return true;
        }
    }

    return false;
}

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis))
                return true;
        }
        else if (it != parent)
            return true;

    return false;
}

bool isCycle_dfs(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);

    for (int node = 0; node < V; node++)
        if (!vis[node])
            if (dfs(node, -1, adj, vis))
                return true;

    return false;
}

int main()
{
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

    if (isCycle_dfs(n, adj))
        cout << "Cycle is there" << endl;
    else
        cout << "Cycle isn't there" << endl;

    return 0;
}