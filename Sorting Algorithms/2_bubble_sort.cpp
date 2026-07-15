// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// bubble sort algorithm
// bubble sort is a STABLE algorithm

/*Repeatedly swap two adjacent elements
if they are in wrong order*/

// Time: O(n^2) in all cases (no early-exit flag, so it doesn't stop early even if already sorted) | Space: O(1)
void bubble_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (vct[j + 1] < vct[j])
                swap(vct[j], vct[j + 1]);
}

// Time: O(n^2) in all cases | Space: O(n) recursion stack
void recursive_bubble_sort(vector<int> &vct, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
        if (vct[i] > vct[i + 1])
            swap(vct[i], vct[i + 1]);

    recursive_bubble_sort(vct, n - 1);
}

int main()
{
    vector<int> vct{12, 45, 23, 51, 19, 8};

    bubble_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
