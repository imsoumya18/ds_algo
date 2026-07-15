// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// Time: O(V^2) | Space: O(1)
void printMatrix(vector<vector<int>> &dist)
{
    for (auto &row : dist)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}

// Time: O(V^3) | Space: O(1) extra (updates the given V x V matrix in place)
void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                dist[i][j] = 0;
            else if (dist[i][j] == -1)
                dist[i][j] = INT_MAX;

    for (int via = 0; via < n; via++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX && dist[i][via] + dist[via][j] < dist[i][j])
                    dist[i][j] = dist[i][via] + dist[via][j];

    for (int i = 0; i < n; i++)
        if (dist[i][i] < 0)
        {
            cout << "Negative cycle exists" << endl;
            return;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] == INT_MAX)
                dist[i][j] = -1;
}

int main()
{
    vector<vector<int>> dist{{0, 4, -1, 5, -1},
                             {-1, 0, 1, -1, 6},
                             {2, -1, 0, 3, -1},
                             {-1, -1, 1, 0, 2},
                             {1, -1, -1, 4, 0}};

    cout << "before:" << endl;
    printMatrix(dist);

    floydWarshall(dist);

    cout << "after:" << endl;
    printMatrix(dist);

    return 0;
}