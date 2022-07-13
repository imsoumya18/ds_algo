// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// binary search algorithm
int binary_search(vector<int> vct, int n, int first, int last)
{
    if (first <= last)
    {
        int mid = first + (last - first) / 2;

        if (vct[mid] == n)
            return mid;

        else if (vct[mid] > n)
            return binary_search(vct, n, first, mid - 1);

        else
            return binary_search(vct, n, mid + 1, last);
    }

    return -1;
}

int main()
{
    vector<int> vct{-35, -2, 27, 48, 95};
    int n = 95;

    cout << binary_search(vct, n, 0, vct.size() - 1);

    return 0;
}
