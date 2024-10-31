// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// insertion sort algorithm
// insertion sort is a STABLE algorithm

/*insert an element from unsorted array
to its corect position in sorted array*/

void insertion_sort(vector<int> &vct)
{
    for (int i = 1; i < vct.size(); i++)
    {
        int temp = vct[i];
        int j = i - 1;

        while (vct[j] > temp && j >= 0)
        {
            vct[j + 1] = vct[j];
            j--;
        }

        vct[j + 1] = temp;
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
