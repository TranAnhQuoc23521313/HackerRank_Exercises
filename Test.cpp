#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>

#define NumberOfFile 1
using namespace std;

void output(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int formingMagicSquare(vector<vector<int>> &s)
{
    int Sum_Cross = 0;
    set<int> Sum_Set;
    for (int i = 0; i < 3; i++)
    {
        int Sum_Row = 0;
        int Sum_Col = 0;
        for (int j = 0; j < 3; j++)
        {
            Sum_Row += s[i][j];
            Sum_Col += s[j][i];
        }
        Sum_Cross += s[i][i];
        s[i][3] = Sum_Row;
        s[3][i] = Sum_Col;
        Sum_Set.insert(Sum_Col);
        Sum_Set.insert(Sum_Row);
    }
    s[3][3] = Sum_Cross;
    Sum_Set.insert(Sum_Cross);
    set<int> Res_Set;
    int Max_Magic_Value = *Sum_Set.rbegin();
    for (int Max_Value = Max_Magic_Value; Max_Value <= 27; Max_Value++)
    {
        int Res = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (s[i][j] + abs(s[i][3]-Max_Value) <= 9)
                {
                    Res += abs(s[i][3]-Max_Value);
                    s[i][j] += abs(s[i][3]-Max_Value);
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < 3; i++)
        {
            if (s[i][3] != Max_Value || s[3][i] != Max_Value)
                flag = false;
        }
        if (flag)
            return Res;
    }

    return 0;
}

int main()
{
    vector<vector<int>> Arr(4, vector<int>(4, 0));

    ifstream fi("input.inp");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            fi >> x;
            Arr[i][j] = x;
        }
    }

    int Result = formingMagicSquare(Arr);

    ofstream fo("output.out");
    for (vector<int> x : Arr)
    {
        for (int y : x)
            fo << y << " ";
        fo << endl;
    }
    fo << "RES = " << Result << endl;
    return 0;
}

// 5 3 4 12
// 1 5 8 14
// 6 4 2 12
// 12 12 14 12
