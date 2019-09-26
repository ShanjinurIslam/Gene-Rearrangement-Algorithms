#include <iostream>
#include <vector>
#include "basic_functions.h"
using namespace std;

bool checkIdentity(vector<int> bases)
{
    bool flag = true;
    for (int i = 1; i < bases.size(); i++)
    {
        if (i != bases[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int findPosition(vector<int> bases, int value)
{
    int index = -1;
    for (int i = 1; i < bases.size(); i++)
    {
        if (bases[i] == value)
        {
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<int> bases;
    int b;
    bases.push_back(0);
    while (true)
    {
        cin >> b;

        if (b == -1)
            break;
        else
            bases.push_back(b);
    }

    int n = bases.size();
    for (int i = 1; i <= n - 1; i++)
    {
        int j = findPosition(bases, i);
        if (i != j)
        {
            bases = reverse(bases, i, j);
            cout << "Reversal: "
                 << "(" << i << "," << j << ")" << endl;
        }
        if (checkIdentity(bases))
            break;
    }
    print(bases);

    return 0;
}