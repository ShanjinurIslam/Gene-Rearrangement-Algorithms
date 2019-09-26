#include <iostream>
#include <vector>
#include <utility>
#include "basic_functions.h"

using namespace std;

bool checkDecreasingStrip(vector<int> bases)
{
    for (int i = 0; i < bases.size(); i++)
    {
        if (bases[i] == bases[i + 1] + 1)
        {
            return true;
        }
    }
    return false;
}

pair<int, int> findIncreasingStrip(vector<int> bases)
{
    pair<int, int> limits;
    limits.first = -1;
    limits.second = -1;
    for (int i = 0; i < bases.size(); i++)
    {
        if (bases[i] + 1 == bases[i + 1])
        {
            limits.first = i;
            break;
        }
    }
    for (int i = limits.first + 1; i < bases.size() - 1; i++)
    {
        if (bases[i] + 1 != bases[i + 1])
        {
            break;
        }
        else
            limits.second = i + 1;
    }
    return limits;
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
    bases.push_back(bases.size());
    while (breakPoints(bases) > 0)
    {
        int b = breakPoints(bases);
        vector<int> result;
        if (checkDecreasingStrip(bases))
        {
            for (int i = 0; i < bases.size() - 1; i++)
            {
                for (int j = i + 1; j < bases.size(); j++)
                {
                    vector<int> temp = bases;
                    temp = reverse(temp, i, j);
                    int t = breakPoints(temp);
                    if (t < b)
                    {
                        b = t;
                        result = temp;
                        cout << "Reversal: "
                             << "(" << i << "," << j << ")" << endl;
                    }
                }
            }
            bases = result;
        }
        else
        {
            pair<int, int> limits = findIncreasingStrip(bases);

            if (limits.first != -1 || limits.second == -1)
            {
                cout << "Reversal: "
                     << "(" << limits.first << "," << limits.second << ")" << endl;

                bases = reverse(bases, limits.first, limits.second);
            }
        }
    }

    print2(bases);
    return 0;
}