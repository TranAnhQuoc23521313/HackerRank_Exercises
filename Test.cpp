#include <bits/stdc++.h>

#define NumberOfFile 1
#define InputFile "input.inp"
#define OutputFile "output.out"
using namespace std;

pair<int,int> Find_Max(vector<int> Array)
{
    int max = 0;
    int index = 0;
    for (int i = 1; i < Array.size()-1; i++)
    {
        if (Array[i] >= Array[index])
        {
            max = Array[i];
            index = i;
        }
    }
    return make_pair(max, index);
}

string ThunderForce(int x,vector<int> Array)
{
    for (int i = 0; i < x-1 ;i++)
    {
        pair<int,int> max = Find_Max(Array); // First = max, second = index
        if (Array[max.second -1] - 1 >= 0 && Array[max.second]-2 >= 0 && Array[max.second + 1] - 1 >= 0)
        {
            Array[max.second - 1]--;
            Array[max.second] -= 2;
            Array[max.second + 1]--;
        }
    }
    for (int value:Array)
        cout << value << " ";
    for (int value:Array)
        if (value != 0)
            {
                cout << "NO" << endl;
                return "NO";
            }
    cout << "YES" << endl;
    return "YES";
}

int main()
{
    ifstream fi(InputFile);
    int testcase;
    fi >> testcase;
    vector<string> Result(testcase);
    for (int i = 0; i < testcase; i++)
    {
        int x;
        fi >> x;
        vector<int> Array(x);
        for (int j = 0; j < x; j++)
            fi >> Array[j];
        Result.push_back(ThunderForce(x, Array));
    }

    ofstream fo(OutputFile);
    for (int i = 0; i < testcase; i++)
    {
        cout << Result[i] << endl;
    }
    return 0;
}