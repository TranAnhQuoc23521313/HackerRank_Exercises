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

int beautifulTriplets(int d, vector<int> arr) 
{
    int count = 0;
    for (int i = 0; i < arr.size();i++)
    {
        for (int j = i+1; j < arr.size();j++)
            {
                if (arr[j]-arr[i]==d)
                    for (int k = j+1; k < arr.size();k++)
                    {
                        if (arr[k]-arr[j]==d)
                        {
                            count++;
                            break;
                        }
                    }
            } 
    }
    return count;
}

int main()
{
    int n,d;
    ifstream fi("input.inp");
    fi >> n >> d;
    vector<int> arr;
    for (int i = 0; i < n;i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }
    ofstream fo("output.out");
    fo << beautifulTriplets(d,arr);
    return 0;
}