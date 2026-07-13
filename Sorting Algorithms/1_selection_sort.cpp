// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// selection sort algorithm
// selection sort is an UNSTABLE sorting algorithm

/*Find the minimum element in unsorted array and swap
it with element at begining*/

void selection_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (vct[j] < vct[i])
                swap(vct[i], vct[j]);
}

int main()
{
    vector<int> vct{12, 45, 23, 51, 19, 8};

    selection_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
