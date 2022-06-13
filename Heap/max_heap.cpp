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

// min heap deletion
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
