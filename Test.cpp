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

vector<int> serviceLane(int n, vector<vector<int>> cases, vector<int> width) 
{
    map<int,int> arr;
    vector<int> result;
    for (int i = 0; i < n;i++)
        arr[i]=width[i];
    for (int i = 0; i < cases.size();i++)
    {
        
    }
}

int main()
{
    int n,t;
    ifstream fi("input.inp");
    fi >> n >> t;
    vector<int> width;
    for (int i = 0; i < n;i++)
    {
        int x;
        fi >> x;
        width.push_back(x);
    }
    vector<vector<int>> cases;
    for (int i = 0; i < t;i++)
    {
        vector<int> row;
        for (int j = 0; j < 2;j++)
        {
            int x;
            fi >> x;
            row.push_back(x);
        }
        cases.push_back(row);
    }
    ofstream fo("output.out");
    fo << n << " " << t << endl;
    for (auto& x:width)
        fo << x << " ";
    fo << endl;
    for (auto& x:cases)
        fo << x[0] << " " << x[1] << endl;
    return 0;
}