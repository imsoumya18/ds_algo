// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// binary search algorithm
int binarySearch(vector<int> vct, int key)
{
    int lo = 0, hi = vct.size() - 1;
    int mid = (lo + hi) / 2;

    while (lo <= hi)
    {
        if (key == vct[mid])
            return mid;
        if (key < vct[mid])
            hi = mid - 1;
        else
            lo = mid + 1;

        mid = (lo + hi) / 2;
    }

    return -1;
}

int main()
{
    vector<int> vct{3, 7, 9, 11, 17, 39};

    cout << binarySearch(vct, 10) << endl;

    return 0;
}
