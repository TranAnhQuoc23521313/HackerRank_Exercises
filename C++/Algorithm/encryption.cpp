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

vector<int> findTheCoupleNumber(int length)
{
    for (int i = 1; i < length;i++)
    {
        if (i*i==length)
            return {i,i};
    }
    for (int border = 0; border < sqrt(length);border++)
    {
        if (border < sqrt(length) && border+1 > sqrt(length))
            return {border,border+1};
    }
    return {0,0};
}

string encryption(string s) 
{
    string new_string;
    for (char ct:s)
    {
        if (ct!=' ')
            new_string+=ct;
    }
    //cout << new_string << endl;
    if (new_string.length() < 3)
        return new_string;
    vector<int> border = findTheCoupleNumber(new_string.length());
    vector<vector<char>> Save_Encryption_string;
    //int row = border[0];
    int column = border[1];
    ///cout << "(" << row << "," << column << ")" << endl;
    int turn = 0;
    string result;
    while (turn < column)
    {
        int position = turn;
        while (position < new_string.length())
        {
            result+=new_string[position];
            //cout << new_string[position];
            position+=column;
        }
        //cout << endl;
        result+=" ";
        turn++;
    }
    return result;
}

int main()
{
    string h;
    vector<string> result;
    ifstream fi("input.inp");
    getline(fi,h);
    ofstream fo("output.out");
    fo << encryption(h);
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

