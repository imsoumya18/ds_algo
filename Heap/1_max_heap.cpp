// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// max heap insertion
void insert(vector<int> &harr, int p)
{
    harr.push_back(p);

    int n = harr.size() - 1;

    while (n > 0)
    {
        if (harr[(n - 1) / 2] < harr[n])
        {
            swap(harr[(n - 1) / 2], harr[n]);

            n = (n - 1) / 2;
        }
        else
            break;
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
        int larger = harr[lc] > harr[rc] ? lc : rc;

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
void heapify(vector<int> &harr, int size, int i)
{
    int largest = i;
    int lc = 2 * i + 1, rc = 2 * i + 2;

    if (lc < size && harr[lc] > harr[largest])
        largest = lc;

    if (rc < size && harr[rc] > harr[largest])
        largest = rc;

    if (largest != i)
    {
        swap(harr[i], harr[largest]);
        heapify(harr, size, largest);
    }
}

// build heap
void buildHeap(vector<int> &harr)
{
    for (int i = harr.size() / 2 - 1; i >= 0; i--)
        heapify(harr, harr.size(), i);
}

// heap sort
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
    vector<int> harr{35, 30, 27, 20, 15, 12, 17, 10};

    // insert(harr, 50);
    // deletion(harr);

    for (auto i : harr)
        cout << i << " ";

    heapSort(harr, harr.size());
    cout << endl;

    for (auto i : harr)
        cout << i << " ";

    return 0;
}
