#include <bits/stdc++.h>

#define NumberOfFile 1
#define InputFile "input.inp"
#define OutputFile "output.out"
using namespace std;

bool Check_Leap_Year(int year)
{
    if (year % 400 == 0)
        return true;
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    if ((year % 4 == 0) && year < 1918)
        return true;
    return false;
}

string dayOfProgrammer(int year) {
    vector<int> Days_Of_Months = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (year == 1918)
    {
        return "26.09." + to_string(year);
    }
    if (Check_Leap_Year(year))
    {
        cout << "LEAP YEAR !" << endl;
        Days_Of_Months[2] = 29;
    }
    int Sum_Days = 0;
    for (int i = 1; i <= 8; i++)
        Sum_Days += Days_Of_Months[i];
    int Date = 256 - Sum_Days;
    string D,Y;
    if (Date >= 10)
        D = to_string(Date);
    else 
        D = "0" + to_string(Date);
    if (year >= 1000)
        Y = to_string(year);
    else 
        Y = "0" + to_string(year);
    string Res = D + ".09." + Y;
    return Res;
}

int main()
{
    ifstream fi(InputFile);
    int year;
    fi >> year;

    ofstream fo(OutputFile);
    string Res = dayOfProgrammer(year);
    fo << Res << endl;
    return 0;
}