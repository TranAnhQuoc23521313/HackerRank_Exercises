#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int>> InputMaTrixVector(int &);

/*Write your code here*/

int main()
{
    int n;
    vector<vector<int>> a = InputMaTrixVector(n);
    
    return 0;
}

vector<vector<int>> InputMaTrixVector(int &n)
{
    vector<vector<int>> arr;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        vector<int> hang;
        for (int j = 0; j < n;j++)
        {
            int x;
            cin >> x;
            hang.push_back(x);
        }
        arr.push_back(hang);
    }
    return arr;
}