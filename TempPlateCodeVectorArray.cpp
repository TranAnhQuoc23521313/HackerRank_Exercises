#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> InputMaTrixVector(int &);

/*Write your code here*/

int main()
{
    int n;
    vector<int> a = InputMaTrixVector(n);
    
    return 0;
}

vector<int> InputMaTrixVector(int &n)
{
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}