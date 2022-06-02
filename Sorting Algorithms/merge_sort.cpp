// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// merge sort algorithm

void merge(vector<int> &vct, int l, int mid, int r)
{
    vector<int> arr1, arr2;

    for (int i = l; i <= mid; i++)
        arr1.push_back(vct[i]);

    for (int i = mid + 1; i <= r; i++)
        arr2.push_back(vct[i]);

    int i = l, j = 0, k = 0;

    while (j < arr1.size() && k < arr2.size())
    {
        if (arr1[j] < arr2[k])
        {
            vct[i] = arr1[j];
            i++;
            j++;
        }
        else
        {
            vct[i] = arr2[k];
            i++;
            k++;
        }
    }

    while (j < arr1.size())
    {
        vct[i] = arr1[j];
        i++;
        j++;
    }

    while (k < arr2.size())
    {
        vct[i] = arr2[k];
        i++;
        k++;
    }
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
