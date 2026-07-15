// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

class DisJointSet
{
    vector<int> rank, parent, size;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    // Time: O(a(n)) amortized (inverse Ackermann, effectively O(1)) thanks to
    // path compression | Space: O(a(n)) recursion stack, effectively O(1)
    int findUltParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltParent(parent[node]);
    }

    // Time: O(a(n)) amortized | Space: O(1) (excluding the findUltParent recursion)
    void unionByRank(int u, int v)
    {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
        {
            // either one is right
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Time: O(a(n)) amortized | Space: O(1) (excluding the findUltParent recursion)
    void unionBySize(int u, int v)
    {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            // either one is right
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    DisJointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    /* sets after the unions above:
       {1, 2, 3}   {4, 5, 6, 7}
       3 and 7 are in different sets so far
    */

    // Check if 3 & 7 have same parent or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;

    ds.unionBySize(3, 7);
    /* after unionBySize(3, 7), the two sets merge into one:
       {1, 2, 3, 4, 5, 6, 7}
    */

    // Check if 3 & 7 have same parent or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;

    return 0;
}