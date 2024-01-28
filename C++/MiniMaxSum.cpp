#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> InputMaTrixVector(int &);

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    long min = 0;
    long max = 0;
    for (int i = 0; i < 4;i++)
        min += arr[i];
    //cout << min;
    for (int i=arr.size()-1;i > arr.size()-5;i--)
        max += arr[i];
    cout << min << " " << max;
}

int main()
{
    int n;
    vector<int> a = InputMaTrixVector(n);
    miniMaxSum(a);
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
        //cout << arr[i] << "*";
    }
    return arr;
}