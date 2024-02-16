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

int chocolateFeast(int n, int c, int m) 
{
    int chocolate = n/c;
    int ticket = n/c;
    while (ticket >= m)
    {
        chocolate++;
        ticket = ticket-m+1;
    }
    return chocolate;
}

int main()
{
    int n;
    ifstream fi("input.inp");
    fi >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n;i++)
    {
        vector<int> row;
        for (int i = 0; i < 3;i++)
        {
            int x;
            fi >> x;
            row.push_back(x);
        }
        arr.push_back(row);
    }
    ofstream fo("output.out");
    int i = 1;
    for (auto& x:arr)
    {
        fo << "Case #"<< i << ": " << chocolateFeast(x[0],x[1],x[2]) << endl;
        i++;
    }
    return 0;
}