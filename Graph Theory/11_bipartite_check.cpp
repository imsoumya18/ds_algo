// @author Soumya
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// colour[node] alternates 0/1 across every edge; a graph is bipartite iff this
// is always possible, i.e. no edge ever connects two same-coloured nodes

// Time: O(V + E) | Space: O(V) for colour[] + queue
bool bfs(int start, vector<vector<int>> &adj, vector<int> &colour)
{
    queue<int> q;
    q.push(start);
    colour[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
            if (colour[it] == -1)
            {
                q.push(it);
                colour[it] = 1 - colour[node];
            }
            else if (colour[it] == colour[node])
                return false;
    }

    return true;
}

// Time: O(V + E) | Space: O(V) for colour[] + queue (drives bfs() over every component)
bool isBipartite_bfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> colour(n, -1);

    for (int i = 0; i < n; i++)
        if (colour[i] == -1 && !bfs(i, adj, colour))
            return false;

    return true;
}

// Time: O(V + E) | Space: O(V) for colour[] + recursion stack
bool dfs(int start, vector<vector<int>> &adj, vector<int> &colour, int fillColour)
{
    colour[start] = fillColour;

    for (auto it : adj[start])
        if (colour[it] == -1 && !dfs(it, adj, colour, 1 - fillColour))
            return false;
        else if (colour[it] == colour[start])
            return false;

    return true;
}

// Time: O(V + E) | Space: O(V) for colour[] + recursion stack (drives dfs() over every component)
bool isBipartite_dfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> colour(n, -1);

    for (int i = 0; i < n; i++)
        if (colour[i] == -1 && !dfs(i, adj, colour, 0))
            return false;

    return true;
}

int main()
{
    /* sample input (bipartite: even cycle 0-1-2-3-0):
       4 4
       0 1
       1 2
       2 3
       3 0

       graph:
         0 --- 1
         |     |
         3 --- 2
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

    cout << (isBipartite_bfs(adj) ? "Bipartite" : "Not Bipartite") << endl;
    cout << (isBipartite_dfs(adj) ? "Bipartite" : "Not Bipartite") << endl;

    return 0;
}
