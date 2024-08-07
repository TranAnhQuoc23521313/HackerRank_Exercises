#include <bits/stdc++.h>

#define NumberOfFile 1
using namespace std;

bool Check(int s,int t,int value)
{
    if (value < s)
        return false;
    if (value > t)
        return false;
    return true;
}

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {

    // Traverse for the apple first
    int Count_Apple = 0; 
    //cout << "A = " << a << endl;
    for (int apple_value:apples)
    {
        int distance = a + apple_value;
        //cout << distance << endl;
        if (Check(s,t,distance))
            Count_Apple++;
    }

    // Traverse for the oranges second
    int Count_Orange = 0;
    //cout << "B = " << b << endl;
    for (int orange_value:oranges)
    {
        int distance = b + orange_value;
        //cout << distance << endl;
        if (Check(s,t,distance))
            Count_Orange++;
    }
    // ofstream fo("output.out");
    // fo << Count_Apple << endl << Count_Orange << endl;
    cout << Count_Apple << endl << Count_Orange << endl;
}

int main()
{
    vector<int> arr;

    ifstream fi("input.inp");
    int s,t,a,b,apple_num,orange_num;
    fi >> s >> t;
    fi >> a >> b;
    fi >> apple_num >> orange_num;
    vector<int> Apple,Orange;
    for (int i = 0; i < apple_num; i++)
    {
        int value;
        fi >> value;
        Apple.push_back(value);
    }

    for (int i = 0; i < orange_num; i++)
    {
        int value;
        fi >> value;
        Orange.push_back(value);
    }

    countApplesAndOranges(s,t,a,b,Apple,Orange);
    return 0;
}