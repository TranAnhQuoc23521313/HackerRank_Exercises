#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> InputMaTrixVector(int &,int &);

int nonDivisibleSubset(int k, vector<int>& arr) 
{
    vector<int> demsodu(k,0);
    for (int num:arr)
        demsodu[num%k]++;
    int result = min(demsodu[0],1);
    for (int i = 1; i <= k/2;i++)
        if (i+i!=k)
            result+=max(demsodu[i],demsodu[k-i]);
    if (k%2==0 )
        result++;
    return result;
}

int main()
{
    int n,k;
    vector<int> a = InputMaTrixVector(n,k);
    cout << nonDivisibleSubset(k,a);
    return 0;
}

vector<int> InputMaTrixVector(int &n,int&k)
{
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}