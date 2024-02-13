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

#define NumberOfFile 1
using namespace std;

int minimumDistances(vector<int> a) 
{
    map<int,int> arr;
    for (int i = 0; i < a.size();i++)
    {
        if (arr.find(a[i])==arr.end())
            arr[a[i]]=1;
        else 
            arr[a[i]]++;
    }
    map<int,int> index_a;
    for (int i = 0; i < a.size();i++)
    {
        index_a[i]=a[i];
    }
    /*for (auto it = arr.begin(); it != arr.end();it++)
        cout << it->first << " " << it->second << endl;*/
    vector<int> couple_value;
    for (auto it = arr.begin(); it != arr.end();it++)
    {
        if (it->second == 2)
            couple_value.push_back(it->first);
    }
    if (couple_value.empty())
        return -1;
    //cout << "Distance btw the couple" << endl;
    vector<int> distance_index;
    for (int i = 0; i < couple_value.size();i++)
    {
        int value = couple_value[i];
        vector<int> temp;
        for (int i = 0; i < index_a.size();i++)
        {
            if (index_a[i]==value)
                temp.push_back(i);
        }
        int d = abs(temp[1]-temp[0]);
        distance_index.push_back(d);
    }
    return *min_element(distance_index.begin(),distance_index.end());
}

int main()
{
    int n,d;
    ifstream fi("input.inp");
    fi >> n;
    vector<int> arr;
    for (int i = 0; i < n;i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }
    ofstream fo("output.out");
    fo << minimumDistances(arr);
    return 0;
}