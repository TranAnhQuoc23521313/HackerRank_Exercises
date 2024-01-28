#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int>> InputMaTrixVector(int &);
void OutputMaTrixVector(int,vector<vector<int>>);
int main()
{
    int n;
    vector<vector<int>> a = InputMaTrixVector(n);
    OutputMaTrixVector(n,a);
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

void OutputMaTrixVector(int n,vector<vector<int>> arr)
{
    for (int i =0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}