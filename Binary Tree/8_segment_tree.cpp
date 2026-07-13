// @author Soumya
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// build a segment tree for range maximum query
void build(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(arr, tree, 2 * node + 1, start, mid);
    build(arr, tree, 2 * node + 2, mid + 1, end);

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

// point update: set arr[idx] = val
void update(vector<int> &arr, vector<int> &tree, int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;

    if (idx <= mid)
        update(arr, tree, 2 * node + 1, start, mid, idx, val);
    else
        update(arr, tree, 2 * node + 2, mid + 1, end, idx, val);

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

// range maximum query over [l, r]
int query(vector<int> &tree, int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return INT_MIN; // this node's range is entirely outside [l, r]

    if (l <= start && end <= r)
        return tree[node]; // this node's range is entirely inside [l, r]

    int mid = (start + end) / 2;
    int leftMax = query(tree, 2 * node + 1, start, mid, l, r);
    int rightMax = query(tree, 2 * node + 2, mid + 1, end, l, r);

    return max(leftMax, rightMax);
}

// apply this node's pending update to itself, and hand it down to its children
// (without this, a range update would have to touch every leaf in the range,
// costing O(n) instead of O(log n))
void pushDown(vector<int> &tree, vector<int> &lazy, int node, int start, int end)
{
    if (lazy[node] == 0)
        return;

    tree[node] += lazy[node];

    if (start != end) // not a leaf: children inherit the pending update, still undone
    {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }

    lazy[node] = 0;
}

// range update: add val to every element in arr[l..r]
void updateRange(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int l, int r, int val)
{
    pushDown(tree, lazy, node, start, end);

    if (r < start || end < l)
        return; // no overlap

    if (l <= start && end <= r)
    {
        // fully covered: record the pending update here instead of recursing further
        lazy[node] += val;
        pushDown(tree, lazy, node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    updateRange(tree, lazy, 2 * node + 1, start, mid, l, r, val);
    updateRange(tree, lazy, 2 * node + 2, mid + 1, end, l, r, val);

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

// range maximum query over [l, r], aware of not-yet-applied lazy updates
int queryRange(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int l, int r)
{
    pushDown(tree, lazy, node, start, end);

    if (r < start || end < l)
        return INT_MIN;

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int leftMax = queryRange(tree, lazy, 2 * node + 1, start, mid, l, r);
    int rightMax = queryRange(tree, lazy, 2 * node + 2, mid + 1, end, l, r);

    return max(leftMax, rightMax);
}

int main()
{
    vector<int> arr{2, 5, 1, 4, 9, 3};
    int n = arr.size();
    vector<int> tree(4 * n);

    build(arr, tree, 0, 0, n - 1);
    /* arr (0-indexed): 2 5 1 4 9 3

       segment tree (node : [range] = max), root at index 0,
       children of node i live at 2i+1 and 2i+2:

                                 0:[0,5]=9
                                /          \
                          /                     \
                    /                                 \
               1:[0,2]=5                            2:[3,5]=9
                /     \                              /      \
            /             \                       /            \
         /                   \                /                   \
      3:[0,1]=5         4:[2,2]=1          5:[3,4]=9          6:[5,5]=3
        /   \                               /     \
     /         \                          /         \
  /               \                    /               \
7:[0,0]=2   8:[1,1]=5               11:[3,3]=4   12:[4,4]=9
    */

    cout << query(tree, 0, 0, n - 1, 1, 4) << endl; // max in arr[1..4] -> 9
    cout << query(tree, 0, 0, n - 1, 0, 2) << endl; // max in arr[0..2] -> 5

    update(arr, tree, 0, 0, n - 1, 2, 10); // arr becomes 2 5 10 4 9 3

    cout << query(tree, 0, 0, n - 1, 0, 2) << endl; // max in arr[0..2] -> 10

    // lazy propagation: range update instead of point update
    // tree currently reflects arr = 2 5 10 4 9 3
    vector<int> lazy(4 * n, 0);

    cout << queryRange(tree, lazy, 0, 0, n - 1, 1, 3) << endl; // max in arr[1..3] -> 10 (sanity check, no pending updates yet)

    updateRange(tree, lazy, 0, 0, n - 1, 2, 4, 100); // add 100 to arr[2..4], conceptually: 2 5 110 104 109 3

    cout << queryRange(tree, lazy, 0, 0, n - 1, 1, 3) << endl; // max in arr[1..3] -> 110
    cout << queryRange(tree, lazy, 0, 0, n - 1, 0, 5) << endl; // max in arr[0..5] -> 110

    return 0;
}
