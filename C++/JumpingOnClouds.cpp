#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> InputMaTrixVector(int &);

int jumpingOnClouds(vector<int> c) 
{
    vector<int> f(c.size(),0);
    f[0]=0;
    f[1]=c[1]==0?1:1000000000;
    for (int i = 2; i < c.size();i++)
        if (c[i]==1)
            f[i]=1000000000;
        else 
            f[i]=1+min(f[i-1],f[i-2]);
    //for (int i = 0; i < f.size();i++)
        //cout << f[i] << " ";
    return f[c.size()-1];
}

int main()
{
    int n;
    vector<int> a = InputMaTrixVector(n);
    cout << jumpingOnClouds(a);
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