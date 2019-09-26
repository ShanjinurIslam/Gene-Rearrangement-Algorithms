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
            print(bases);
        }
        if (checkIdentity(bases))
            break;
    }

    return 0;
}