#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int s1 = 0;
    int s2 = 0;
    //cout << arr.size() << endl;
    for (int i=0;i < arr.size();i++)
        for (int j = 0; j < arr[i].size();j++)
        {
            if (i == j)
                s1+=arr[i][j];
            if (i+j+1==arr.size())
                s2+=arr[i][j];
        }
    //cout << s1 << " " << s2;
    return abs(s1-s2);
}

vector<vector<int>> InputMaTrixVector(int &);

int main()
{
    int n;
    vector<vector<int>> a = InputMaTrixVector(n);
    diagonalDifference(a);
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
