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
#include <map>
#include <set>
#define NumberOfFile 1
using namespace std;

string GetInputFileName(int);
string GetOutputFileName(int);
vector<string> Input_Data(int&,int&,string);  // Change the argument following the situation, this is the form
void Output_Data(vector<int> a,string);  // Change the argument following the situation, this is the form

int LengthOfString(string a,string b)
{
    string s;
    int count = 0;
    for (int i = 0; i < a.length();i++)
        if (a[i]=='1' || b[i]=='1')
            s += "1";
    for (char& x:s)
        if(x=='1')
            count++;
    return count;
}

vector<int> acmTeam(vector<string> topic) 
{
    map<int,int> demsoluong;
    for (int i = 0; i < topic.size()-1;i++)
    {
        for (int j = i+1; j < topic.size();j++)
            demsoluong[LengthOfString(topic[i],topic[j])]++;
    }
    auto lc = demsoluong.begin();
    for (auto it = demsoluong.begin(); it != demsoluong.end();++it)
        if (it->first > lc->first)
            lc = it;
    cout << lc->first << " " << lc->second;
    vector<int> result = {lc->first,lc->second};
    return result;
}


int main()
{
    int n,m;
    vector<string> a;
    string File_Input_Name = "input.inp";
    a = Input_Data(m,n,File_Input_Name);
    vector<int> result = acmTeam(a);
    string File_Output_Name = "output.out";
    Output_Data(result,File_Output_Name);
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

vector<string> Input_Data(int &m,int &n,string File_Input_Name)
{
    ifstream fi(File_Input_Name);
    fi >> m >> n;
    vector<string> temp_vector;
    for (int i = 0; i < m;i++)
    {
        string x;
        fi >> x;
        temp_vector.push_back(x);
    }
    return temp_vector;
}

void Output_Data(vector<int> a,string File_Output_Name)
{
    ofstream fo(File_Output_Name);
    for (auto& row:a)
    {
        fo << row << endl;
    }
    fo.close();
}