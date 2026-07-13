// @author Soumya
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> dijkstra_using_pq(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<vector<pair<int, int>>> adj(V);

    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    minHeap.push({0, src});

    while (!minHeap.empty())
    {
        int node = minHeap.top().second;
        int dis = minHeap.top().first;
        minHeap.pop();

        for (auto it : adj[node])
        {
            int nd = it.first;
            int d = it.second;

            if (dis + d < dist[nd])
            {
                dist[nd] = dis + d;
                minHeap.push({dist[nd], nd});
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}

vector<int> dijkstra_using_set(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<vector<pair<int, int>>> adj(V);

    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    set<pair<int, int>> st;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        int dis = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());

        for (auto it : adj[node])
        {
            int nd = it.first;
            int d = it.second;

            if (dist[node] + d < dist[nd])
            {
                if (dist[nd] != INT_MAX)
                    st.erase({dist[nd], nd});

                dist[nd] = dist[node] + d;
                st.insert({dist[nd], nd});
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}

int main()
{
    vector<vector<int>> edges{{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 1}, {2, 3, 5}, {3, 4, 3}};
    int V = 5, src = 0;
    /* graph (edge weights shown):
            4         1
        0 ------ 1 ------ 3 ------ 4
         \       |        /   3
          \1     |2      /5
           \      |     /
            ----- 2 ----
       src = 0
       shortest dist from 0: [0, 3, 1, 4, 7]
    */

    for (auto it : dijkstra_using_pq(V, edges, src))
        cout << it << " ";

    cout << endl;

    for (auto it : dijkstra_using_set(V, edges, src))
        cout << it << " ";

    cout << endl;

    return 0;
}