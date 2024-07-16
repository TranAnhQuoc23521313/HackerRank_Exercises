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

int min_map(map<int,int> arr)
{
    int min = arr.begin()->second;

    for (auto i = arr.begin(); i != arr.end();i++)
        if (i->second < min)
            min = i->second;

    return min;
}

vector<int> cutTheSticks(vector<int> arr)
{
    int n = arr.size();

    vector<int> result= {n};
    map<int,int> New_arr;

    for (int i = 0 ; i < arr.size();i++)
        New_arr[i]=arr[i];

    while (!New_arr.empty())
    {
        int min_arr = min_map(New_arr);
        vector<int> Special_Index;

        for (auto i = New_arr.begin(); i != New_arr.end();i++)
        {
            i->second-=min_arr;

            if (i->second==0)
                Special_Index.push_back(i->first);

        }

        for (int i = 0; i < Special_Index.size();i++)
            New_arr.erase(Special_Index[i]);

        Special_Index.clear();

        for (auto i = New_arr.begin(); i != New_arr.end();i++)
            cout << i->second << " ";
        cout << endl;

        if (New_arr.size()>=1)
            result.push_back(New_arr.size());
            
    }
    return result;
}

int main()
{
    int n;
    vector<int> arr, result;
    ifstream fi("input.inp");
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }
    result = cutTheSticks(arr);
    ofstream fo("output.out");
    for (int i = 0; i < result.size(); i++)
    {
        fo << result[i] << endl;
    }
    return 0;
}