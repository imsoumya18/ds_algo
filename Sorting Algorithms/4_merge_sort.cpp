// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// merge sort algorithm

void merge(vector<int> &vct, int l, int mid, int r)
{
    vector<int> temp;
    int left = l, right = mid + 1;

    while (left <= mid && right <= r)
        if (vct[left] <= vct[right])
            temp.push_back(vct[left++]);
        else
            temp.push_back(vct[right++]);

    while (left <= mid)
        temp.push_back(vct[left++]);

    while (right <= r)
        temp.push_back(vct[right++]);

    for (int i = l; i <= r; i++)
        vct[i] = temp[i - l];
}

void merge_sort(vector<int> &vct, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        merge_sort(vct, l, mid);
        merge_sort(vct, mid + 1, r);

        merge(vct, l, mid, r);
    }
}

int main()
{
    vector<int> vct{12, 45, 23, 51, 19, 8};

    merge_sort(vct, 0, vct.size() - 1);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
