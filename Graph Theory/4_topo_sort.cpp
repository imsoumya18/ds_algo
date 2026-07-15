// @author Soumya
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, adj, st, vis);

    st.push(node);
}

// Time: O(V + E) | Space: O(V) for vis[] + stack + recursion stack
vector<int> topo_sort(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    stack<int> st;

    for (int node = 0; node < V; node++)
        if (!vis[node])
            dfs(node, adj, st, vis);

    vector<int> vct;

    while (!st.empty())
    {
        vct.push_back(st.top());
        st.pop();
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