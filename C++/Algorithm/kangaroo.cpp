#include <bits/stdc++.h>

#define NumberOfFile 1
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v2 > v1)
        return "NO";
    int tu = x2 - x1;
    int mau = v1 - v2;
    if (mau == 0)
        return "NO";
    float t = (float)tu/mau;
    int Under = tu / mau;
    if (Under < t && t < Under+1)
        return "NO";
    return "YES";
}

int main()
{
    vector<int> arr;

    ifstream fi("input.inp");
    for (int i = 0; i < 4; i++)
    {
        int value = 0;
        fi >> value;
        arr.push_back(value);
    }

    string Res = kangaroo(arr[0],arr[1],arr[2],arr[3]);

    ofstream fo("output.out");
    fo << Res << endl;
}