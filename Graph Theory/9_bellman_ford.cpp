// @author Soumya
#include <iostream>
using namespace std;

// Time: O(V * E) | Space: O(V) for dist[]
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
        for (auto e : edges)
            if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                dist[e[1]] = dist[e[0]] + e[2];

    for (auto e : edges)
        if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
            return {-1};

    return dist;
}

int main()
{
    vector<vector<int>> edges{{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int V = 5, src = 0;

    vector<int> vct = bellmanFord(V, edges, src);

    for (auto it : vct)
        cout << it << " ";

    return 0;
}