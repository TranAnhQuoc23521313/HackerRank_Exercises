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
vector<int> Input_Data(int&,string);  // Change the argument following the situation, this is the form
void Output_Data(vector<int> a,int,string);  // Change the argument following the situation, this is the form

/*Write your code here*/

int main()
{
    int n;
    vector<int> a;
    //string File_Input_Name = GetInputFileName(i);
    string File_Input_Name = "input.inp";
    a = Input_Data(n,File_Input_Name);
    //string File_Output_Name = GetOutputFileName(i);
    string File_Output_Name = "output.out";
    Output_Data(a,n,File_Output_Name);
    a = vector<int>();
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

vector<int> Input_Data(int &n,string File_Input_Name)
{
    ifstream fi(File_Input_Name);
    fi >> n;
    vector<int> temp_vector;
    for (int i = 0; i < n;i++)
    {
        int x;
        fi >> x;
        temp_vector.push_back(x);
    }
    return temp_vector;
}

void Output_Data(vector<int> a,int n,string File_Output_Name)
{
    ofstream fo(File_Output_Name);
    fo << "n = " << n << endl;
    for (int i = 0; i < n;i++)
        fo << a[i] << " ";
    fo.close();
}