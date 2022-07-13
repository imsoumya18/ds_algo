// @author Soumya
#include <iostream>
#include <vector>
using namespace std;

// linear search algorithm
int linear_search(vector<int> vct, int n)
{
    for (int i = 0; i < vct.size(); i++)
        if (vct[i] == n)
            return i;

    return -1;
}

int main()
{
    vector<int> vct{-2, 7, 2, 95, -76};
    int n = 2;

    cout << linear_search(vct, n);

    return 0;
}
