#include <iostream>
#include <vector>
#include "basic_functions.h"

using namespace std;

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
    print2(bases);
    return 0;
}