// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// max heap insertion
void insert(vector<int> &harr, int p)
{
    harr.push_back(p);

    int n = harr.size() - 1;

    while (n > 1)
    {
        if (harr[(n - 1) / 2] < harr[n])
        {
            swap(harr[(n - 1) / 2], harr[n]);

            n = (n - 1) / 2;
        }
        else
            break;
    }
    if (harr[(n - 1) / 2] < harr[n])
    {
        swap(harr[(n - 1) / 2], harr[n]);

        n = (n - 1) / 2;
    }
}

// max heap deletion
void deletion(vector<int> &harr)
{
    harr[0] = harr[harr.size() - 1];
    harr.pop_back();
    int i = 0;

    while (i < harr.size())
    {
        int lc = i * 2 + 1, rc = i * 2 + 2;
        int larger = harr[lc] > harr[rc] ? i * 2 + 1 : i * 2 + 2;

        if (harr[larger] > harr[i])
        {
            swap(harr[i], harr[larger]);
            i = larger;
        }
        else
            return;
    }
}

// heapify
void heapify(vector<int> &harr, int i)
{
    int largest = i;
    int l = 2 * i, r = 2 * i + 1;

    if (l <= harr.size() && harr[l] > harr[largest])
        largest = l;

    if (r <= harr.size() && harr[r] > harr[largest])
        largest = r;

    if (largest != i)
    {
        swap(harr[i], harr[largest]);
        heapify(harr, largest);
    }
}

// build heap
void buildHeap(vector<int> &harr)
{
    for (int i = harr.size() / 2; i > 0; i--)
        heapify(harr, i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> harr{35, 30, 27, 20, 15, 12, 17, 10};

    insert(harr, 28);
    deletion(harr);

    for (auto i : harr)
        cout << i << " ";

    return 0;
}
