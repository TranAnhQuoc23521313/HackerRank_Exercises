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
#include <queue>
#include <stack>

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

string fairRations(vector<int> arr)
{
    int i = 0;
    int count = 0;
    while (i < arr.size()-1)
    {
        if (arr[i] % 2 != 0)
        {
            output(arr);
            arr[i]++;
            arr[i + 1]++;
            count += 2;
        }
        i++;
    }
    for (vector<int>::iterator i = arr.begin(); i != arr.end();i++)
    {
        if (*i % 2 != 0)
            return "NO";
    }
    return to_string(count);
}

int main()
{
    int n, m;
    vector<int> arr;

    ifstream fi("input.inp");
    fi >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }

    string result = fairRations(arr);

    ofstream fo("output.out");
    fo << result;
    return 0;
}