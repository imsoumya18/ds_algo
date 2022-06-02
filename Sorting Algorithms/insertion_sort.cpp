// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// insertion sort algorithm

/*insert an element from unsorted array
to its corect position in sorted array*/

void insertion_sort(vector<int> &vct)
{
    for (int i = 1; i < vct.size(); i++)
        for (int j = 0; j < i; j++)
            if (vct[i] < vct[j])
            {
                int temp = vct[i];
                for (int k = i; k > j; k--)
                    vct[k] = vct[k - 1];
                vct[j] = temp;
            }
}

int main()
{
    vector<int> vct{12, 45, 23, 51, 19, 8};

    insertion_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
