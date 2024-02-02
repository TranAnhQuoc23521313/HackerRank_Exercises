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

#define NumberOfFile 1
using namespace std;

string GetInputFileName(int);
string GetOutputFileName(int);
vector<vector<long>> Input_Data(int&,string);  // Change the argument following the situation, this is the form
void Output_Data(vector<long long> a,int,string);  // Change the argument following the situation, this is the form

long long taumBday(long long b, long long w, long long bc, long long wc, long long z)
{
    //Case 1: bc > wc + z
    if (bc > (wc+z))
    {
        return (b+w)*wc+b*z;
    }
    //Case 2:
    if (wc > (bc+z))
    {
        return (b+w)*bc+ w*z;
    }
    //Case 3:
    return b*bc+w*wc;
}

int main()
{
    int n;
    vector<vector<long>> a;
    //string File_Input_Name = GetInputFileName(i);
    string File_Input_Name = "input.inp";
    a = Input_Data(n,File_Input_Name);
    vector<long long> result;
    for (auto& row:a)
    {
        result.push_back(taumBday(row[0],row[1],row[2],row[3],row[4]));
    }
    string File_Output_Name = "output.out";
    Output_Data(result,n,File_Output_Name);
    //a = vector<vector<int>>();
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

vector<vector<long>> Input_Data(int &n,string File_Input_Name)
{
    ifstream fi(File_Input_Name);
    fi >> n;
    vector<vector<long>> temp_vector;
    for (int i = 0;i < n;i++)
    {
        vector<long> row;
        for (int j = 0; j < 5;j++)
        {
            int x;
            fi >> x;
            row.push_back(x);
        }
        temp_vector.push_back(row);
    }
    return temp_vector;
}

void Output_Data(vector<long long> a,int n,string File_Output_Name)
{
    ofstream fo(File_Output_Name);
    fo << "n = " << n << endl;
    int i = 1;
    for (auto& row:a)
    {
        fo << "case #" << i << ":" << row << endl << endl;
        i++;
    }
    fo.close();
}