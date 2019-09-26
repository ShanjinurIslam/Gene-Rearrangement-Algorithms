#include <iostream>
#include <vector>
#include "basic_functions.h"

using namespace std;

int breakPoints(vector<int> bases)
{
    int count = 0;
    for (int i = 0; i < bases.size() - 1; i++)
    {
        if (!((bases[i] + 1 == bases[i + 1]) | (bases[i] == 1 + bases[i + 1])))
        {
            count++;
        }
    }
    return count;
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
    while (breakPoints(bases) > 0)
    {
        int b = breakPoints(bases);
        vector<int> result;
        for(int i=0;i<bases.size()-1;i++){
            for(int j=i+1;j<bases.size();j++){
                vector<int> temp = bases;
                temp = reverse(temp,i,j);
                int t = breakPoints(temp);
                if(t<b){
                    b = t ;
                    result = temp;
                }          
            }
        }
        bases = result ;
    }
    print2(bases);
    return 0;
}