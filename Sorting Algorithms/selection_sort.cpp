// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// selection sort algorithm

/*Find the minimum element in unsorted array and swap
it with element at begining*/

void selection_sort(vector<int> &vct)
{
    for (int i = 0; i < vct.size() - 1; i++)
        for (int j = i + 1; j < vct.size(); j++)
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
