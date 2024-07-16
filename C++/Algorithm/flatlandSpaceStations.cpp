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

int flatlandSpaceStations(int n, vector<int> c) 
{
    sort(c.begin(),c.end());
    if (c.size() == n)
        return 0;
    vector<int> max_length_roads;
    if (c[0] != 0)
        max_length_roads.push_back(c[0]);
    if (c[c.size()-1]!=n)
        max_length_roads.push_back(abs(c[c.size()-1]-n+1));
    for (int i = 0; i < c.size()-1;i++)
    {
        int gap = abs(c[i]-c[i+1]);
        if (gap >= 2)
            {
                max_length_roads.push_back(gap/2);
                //cout << gap/2 << endl;
            }
    }
    for (auto& x:max_length_roads)
        cout << x << endl;
    if (max_length_roads.empty())
        return 0;
    return *max_element(max_length_roads.begin(),max_length_roads.end());
}

int main()
{
    int n,m;
    vector<int> arr;

    ifstream fi("input.inp");
    fi >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }

    int result = flatlandSpaceStations(n,arr);

    ofstream fo("output.out");
    fo << result;
    return 0;
}