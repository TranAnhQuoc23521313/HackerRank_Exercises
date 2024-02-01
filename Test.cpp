#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

vector<string> InputMaTrixVector(int &);

/*Write your code here*/

int main()
{
    int n;
    vector<string> a = InputMaTrixVector(n);
    cout << a[1];
    return 0;
}

vector<string> InputMaTrixVector(int &n)
{
    vector<string> arr;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        string x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}