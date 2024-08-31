#include <bits/stdc++.h>

#define NumberOfFile 1
#define InputFile "input.inp"
#define OutputFile "output.out"
using namespace std;

int migratoryBirds(vector<int> arr) {
    set<int> Data_Type_Bird;
    map<int,int> Check_Type;
    for (int i:arr)
    {
        Check_Type[i] = 0;
        Data_Type_Bird.insert(i);
    }
    for (int i:arr)
    {
        Check_Type[i]++;
    }

    int max_bird_sighted = 0;
    for (map<int,int>::iterator i = Check_Type.begin(); i != Check_Type.end(); i++)
    {
        if (max_bird_sighted < i->second)
            max_bird_sighted = i->second;
    }
    for (int bird_type:Data_Type_Bird)
    {
        if (Check_Type[bird_type] == max_bird_sighted)
            return bird_type;
    }
    return -1;
}

int main()
{
    ifstream fi(InputFile);
    int vector_size;
    vector<int> Arr;
    fi >> vector_size;
    for (int i = 0; i < vector_size; i++)
    {
        int value;
        fi >> value;
        Arr.push_back(value);
    }

    ofstream fo(OutputFile);
    int Res = migratoryBirds(Arr);
    fo << Res << endl;
    return 0;
}