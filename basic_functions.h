#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> pi, int i, int j)
{
    int count = 0;
    if (i > j)
    {
        int t = i;
        i = j;
        j = t;
    }
    for (int c = i; c <= (i + j) / 2; c++)
    {
        int temp = pi[c];
        pi[c] = pi[j - count];
        pi[j - count] = temp;
        count++;
    }

    return pi;
}

void print(vector<int> bases)
{
    for (int i = 1; i < bases.size(); i++)
    {
        cout << bases[i] << " ";
    }
    cout << endl;
}

void print2(vector<int> bases)
{
    for (int i = 0; i < bases.size(); i++)
    {
        cout << bases[i] << " ";
    }
    cout << endl;
}