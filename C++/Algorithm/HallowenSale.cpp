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

int howManyGames(int p, int d, int m, int s) 
{
    int sum = 0;
    int count = 0;
    int temp = p;
    while (sum+temp <= s)
    {
        cout << temp << " ";
        sum+=temp;
        count++;
        temp=(temp-d<m)?m:temp-d;
    }
    //cout << endl << sum;
    return count;
}


int main()
{
    int n;
    ifstream fi("input.inp");
    n = 4;
    vector<int> arr;
    for (int i = 0; i < n;i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }
    ofstream fo("output.out");
    fo << howManyGames(arr[0],arr[1],arr[2],arr[3]);
    return 0;
}