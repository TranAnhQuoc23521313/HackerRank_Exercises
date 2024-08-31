#include <bits/stdc++.h>

#define NumberOfFile 1
#define InputFile "input.inp"
#define OutputFile "output.out"
using namespace std;

int birthday(vector<int> s, int d, int m) {
    int Count = 0;
    for (int i = 0; i <= s.size() - m; i++)
    {
        int Sum = 0;
        for (int j = 0; j < m; j++)
        {
            Sum += s[i+j];
        }
        if (Sum == d)
            Count++;
    }
    return Count;
}

int main()
{
    ifstream fi(InputFile);
    int vector_size;
    vector<int> Arr;
    fi >> vector_size;
    for (int i = 0; i < vector_size; i++)
    {
        int value;
        fi >> value;
        Arr.push_back(value);
    }
    int day,month;
    fi >> day >> month;

    ofstream fo(OutputFile);
    int Res = birthday(Arr,day,month);
    fo << Res << endl;
    return 0;
}