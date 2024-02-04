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
void Output(vector<string>,string);

string organizingContainers(vector<vector<long long>> container) 
{
    vector<long long> sum_column;
    vector<long long> sum_row;
    for (auto& x:container)
    {
        int sum = 0;
        for (auto& y:x)
            sum+=y;
        sum_row.push_back(sum);
    }
    for (int i = 0; i < container.size();i++)
    {
        int sum = 0;
        for (int j = 0; j < container.size();j++)
            sum+=container[j][i];
        sum_column.push_back(sum);
    }
    sort(sum_column.begin(),sum_column.end());
    sort(sum_row.begin(),sum_row.end());
    for (int i = 0; i < sum_column.size();i++)
    {
        if (sum_column[i]!=sum_row[i])
            return "Impossible";
    }
    return "Possible";
}

int main()
{
    int q;
    string File_Input_Name = "input.inp";
    string File_Ouput_Name = "output.out";
    ifstream fi(File_Input_Name);
    fi >> q;
    vector<string> result;
    for (int i = 0; i < q;i++)
    {
        vector<vector<long long>> matrix;
        int n;
        fi >> n;
        for (int i = 0; i < n;i++)
        {
            vector<long long> row;
            for (int i = 0; i < n;i++)
            {
                long long x;
                fi >> x;
                row.push_back(x);
            }
            matrix.push_back(row);
        }
        result.push_back(organizingContainers(matrix));
        matrix.clear();
    }
    Output(result,File_Ouput_Name);
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

void Output(vector<string> a,string File_Output_Name)
{
    ofstream fo(File_Output_Name);
    int i = 1;
    for (auto& x:a)
    {
        fo << "Case #" << i <<": " << x << endl;
        i++;
    }
}