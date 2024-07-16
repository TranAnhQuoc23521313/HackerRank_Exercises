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

#define NumberOfFile 1
using namespace std;

string Create_Word(int x)
{
    map<int,string> Quarter;
    Quarter[15]="quarter past ";
    Quarter[30]="half past ";
    Quarter[45]="quarter to ";
    if (x == 15 || x == 45 || x == 30)
        return Quarter[x];
    if (x > 10 && x < 20)
    {
        string a[] = {"eleven","twelve","thirteen","forteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        return a[x-11];
    }
    string dozen[] = {"ten","twenty","thirty","forty","fifty"};
    string unit[] = {"one","two","three","four","five","six","seven","eight","nine"};
    if (x<10)
        return unit[x-1];
    if (x%10==0)
    {
        return dozen[x/10-1];
    }
    int dozen_x = x/10;
    int unit_x = x%10;
    return dozen[dozen_x-1] + " " + unit[unit_x-1];
}

string timeInWords(int h, int m) 
{
    string result;
    if (m == 0)
    {
        result = Create_Word(h) + " o' clock";
        return result;
    }
    if (m==15 || m == 30)
    {
        result = Create_Word(m)+Create_Word(h);
        return result;
    }
    if (m==45)
    {
        result = Create_Word(m)+Create_Word(h+1);
        return result;
    }
    if (m < 30)
    {
        if (m==1)
            result = Create_Word(m) + " minute past " + Create_Word(h);
        else 
            result = Create_Word(m) + " minutes past " + Create_Word(h);
        return result;
    }
    if (m > 30)
    {
        int x = 60-m;
        if (x == 1)
            result = Create_Word(x) + " minute to " + Create_Word(h+1);
        else
            result = Create_Word(x) + " minutes to " + Create_Word(h+1);
        return result;
    }
    return result;
}

int main()
{
    int n;
    ifstream fi("input.inp");
    n = 2;
    vector<int> arr;
    for (int i = 0; i < n;i++)
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }
    ofstream fo("output.out");
    fo << timeInWords(arr[0],arr[1]);
    return 0;
}