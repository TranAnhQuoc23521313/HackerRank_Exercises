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

string GetInputFileName(int);
string GetOutputFileName(int);

string biggerIsGreater(string w) 
{
    int i = w.length()-2;
    while (i >= 0 && w[i] >= w[i+1])
    {
        i--;
    }
    if (i==-1)
        return "no answer";
    int j = w.length()-1;
    while (j > i && w[j] <= w[i])
    {
        j--;
    }
    swap(w[i],w[j]);
    string result;
    for (int k = 0; k <= i;k++)
        result+=w[k];
    for (int k = w.length()-1; k > i;k--)
        result+=w[k];
    //cout << result << endl;
    return result;
}

int main()
{
    int array_length;
    vector<string> s;
    ifstream fi("input.inp");
    fi >> array_length;
    fi.ignore();
    for (int i = 0; i < array_length;i++)
    {
        string h;
        getline(fi,h);
        s.push_back(h);
        //cout << h << endl;
    }
    ofstream fo("output.out");
    for (int i = 0; i < array_length;i++)
    {
        fo << biggerIsGreater(s[i]) << endl;
    }
    return 0;
}

string GetInputFileName(int x)
{
    string NameFileInput = "input_";
    if (x < 10)
        NameFileInput += "0" + to_string(x) + ".in";
    else
        NameFileInput += to_string(x)+".in";
    return NameFileInput;
}

string GetOutputFileName(int x)
{
    string NameFileOutput = "output_";
    if (x < 10)
        NameFileOutput += "0" + to_string(x) + ".out";
    else
        NameFileOutput += to_string(x)+ ".out";
    return NameFileOutput;
}

