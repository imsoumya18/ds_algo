// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// bubble sort algorithm
// bubble sort is a STABLE algorithm

/*Repeatedly swap two adjacent elements
if they are in wrong order*/

void bubble_sort(vector<int> &vct)
{
    int n = vct.size();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (vct[j + 1] < vct[j])
                swap(vct[j], vct[j + 1]);
}

int main()
{
    vector<int> vct{12, 45, 23, 51, 19, 8};

    bubble_sort(vct);

    for (auto i : vct)
        cout << i << " ";

    return 0;
}
