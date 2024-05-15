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

bool check(vector<char> border, char pos)
{
    for (auto &x : border)
        if (pos <= x)
            return false;
    return true;    
}

vector<string> cavityMap(vector<string> grid)
{
    vector<string> res = grid;
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 1; i < grid.size() - 1; i++)
        for (int j = 1; j < grid.size() - 1; j++)
        {
            vector<char> check_pos;
            for (auto &x : direction)
                check_pos.push_back(grid[i + x.first][j + x.second]);
            if (check(check_pos, grid[i][j]))
                res[i][j] = 'X';
        }
    return res;
}

int main()
{
    int n;
    vector<string> arr;

    ifstream fi("input.inp");
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        string Input;
        fi >> Input;
        arr.push_back(Input);
    }

    vector<string> result = cavityMap(arr);

    ofstream fo("output.out");
    for (string x : result)
        fo << x << endl;
    return 0;
}