// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// quick sort algorithm

/*Choose an element and place
it in its correct position*/

// Time: O(r - l) | Space: O(1)
int partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
        if (nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }

    swap(nums[i + 1], nums[r]);
    return i + 1;
}

// Time: O(n log n) average, O(n^2) worst (e.g. already-sorted input, since the
// pivot is always the last element) | Space: O(log n) avg, O(n) worst recursion stack
void quick_sort(vector<int> &nums, int l, int r)
{
    if (l < r)
    {
        int pi = partition(nums, l, r);

        quick_sort(nums, l, pi - 1);
        quick_sort(nums, pi + 1, r);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vct{12, 45, 23, 51, 19, 8};

    quick_sort(vct, 0, vct.size() - 1);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
