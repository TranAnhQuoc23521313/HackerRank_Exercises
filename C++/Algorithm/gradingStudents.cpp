#include <bits/stdc++.h>

#define NumberOfFile 1
using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    vector<int> Res;
    for (int i:grades)
    {
        if (i < 38)
        {
            Res.push_back(i);
            continue;
        }
        int multiple_5 = (i / 5 + 1) * 5;
        //cout << multiple_5 << endl;
        if (multiple_5 - i < 3)
            Res.push_back(multiple_5);
        else 
            Res.push_back(i);
    }
    return Res;
}

int main()
{
    int n;
    vector<int> arr;

    ifstream fi("input.inp");
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        int Input;
        fi >> Input;
        arr.push_back(Input);
    }

    vector<int> result = gradingStudents(arr);

    ofstream fo("output.out");
    for (int x : result)
        fo << x << endl;
    //fo << "K" << endl;
    return 0;
}