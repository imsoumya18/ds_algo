// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// min heap insertion
// Time: O(log n) | Space: O(1)
void insert(vector<int> &harr, int p)
{
    harr.push_back(p);

    int n = harr.size() - 1;

    while (n > 0)
    {
        if (harr[(n - 1) / 2] > harr[n])
        {
            swap(harr[(n - 1) / 2], harr[n]);

            n = (n - 1) / 2;
        }
        else
            break;
    }
}

// min heap deletion
// Time: O(log n) | Space: O(1)
void deletion(vector<int> &harr)
{
    harr[0] = harr[harr.size() - 1];
    harr.pop_back();
    int n = harr.size();
    int i = 0;

    while (true)
    {
        int lc = i * 2 + 1, rc = i * 2 + 2;
        int smallest = i;

        if (lc < n && harr[lc] < harr[smallest])
            smallest = lc;

        if (rc < n && harr[rc] < harr[smallest])
            smallest = rc;

        if (smallest == i)
            return;

        swap(harr[i], harr[smallest]);
        i = smallest;
    }
}

// heapify
// Time: O(log n) | Space: O(log n) recursion stack
void heapify(vector<int> &harr, int size, int i)
{
    int smallest = i;
    int lc = 2 * i + 1, rc = 2 * i + 2;

    if (lc < size && harr[lc] < harr[smallest])
        smallest = lc;

    if (rc < size && harr[rc] < harr[smallest])
        smallest = rc;

    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        heapify(harr, size, smallest);
    }
}

// build heap
// Time: O(n) (not O(n log n) - most nodes are near the bottom where heapify
// does very little work; the tighter amortized bound works out to O(n))
// Space: O(log n) recursion stack
void buildHeap(vector<int> &harr)
{
    for (int i = harr.size() / 2 - 1; i >= 0; i--)
        heapify(harr, harr.size(), i);
}

// heap sort (descending, since each extracted min lands at the end)
// Time: O(n log n) | Space: O(log n) recursion stack (in-place otherwise)
void heapSort(vector<int> &harr, int n)
{
    int size = n;

    while (size > 1)
    {
        swap(harr[0], harr[size - 1]);
        size--;

        heapify(harr, size, 0);
    }
}

int main()
{
    vector<int> harr{10, 12, 15, 17, 20, 27, 30, 35};
    /* array as a complete binary tree:
                    10
                 /      \
               12        15
              /  \       /  \
            17   20    27   30
            /
          35
    */

    // insert(harr, 5);
    // deletion(harr);

    for (auto i : harr)
        cout << i << " ";

    heapSort(harr, harr.size());
    cout << endl;

    for (auto i : harr)
        cout << i << " ";

    return 0;
}
