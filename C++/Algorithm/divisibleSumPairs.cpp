#include <bits/stdc++.h>

#define NumberOfFile 1
#define InputFile "input.inp"
#define OutputFile "output.out"
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> arr) {
    int Count = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (((arr[i] + arr[j]) % k)  == 0)
                Count++;
        }
    }
    return Count;
}

int main()
{
    ifstream fi(InputFile);
    int vector_size,k;
    vector<int> Arr;
    fi >> vector_size >> k;
    for (int i = 0; i < vector_size; i++)
    {
        int value;
        fi >> value;
        Arr.push_back(value);
    }

    ofstream fo(OutputFile);
    int Res = divisibleSumPairs(vector_size,k,Arr);
    fo << Res << endl;
    return 0;
}