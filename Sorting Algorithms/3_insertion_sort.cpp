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

        while (j >= 0 && vct[j] > temp)
        {
            vct[j + 1] = vct[j];
            j--;
        }

        vct[j + 1] = temp;
    }
}

void recursive_insertion_sort(vector<int> &vct, int n)
{
    if (n == 1)
        return;

    recursive_insertion_sort(vct, n - 1);

    int tmp = vct[n - 1];
    int i = n - 2;

    while (i >= 0 && vct[i] > tmp)
    {
        vct[i + 1] = vct[i];
        i--;
    }

    vct[i + 1] = tmp;
}

int main()
{
    vector<int> vct{12, 45, 23, 51, 19, 8};

    insertion_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
