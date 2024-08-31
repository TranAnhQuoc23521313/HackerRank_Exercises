#include <bits/stdc++.h>

#define NumberOfFile 1
#define InputFile "input.inp"
#define OutputFile "output.out"
using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    int max_score = scores[0];
    int min_score = scores[0];
    int break_highest_score = 0;
    int break_lowest_score = 0;
    for (int index = 1; index < scores.size(); index++)
    {
        if (scores[index] > max_score)
        {
            break_highest_score++;
            max_score = scores[index];
        }
        else if (scores[index] < min_score)
        {
            break_lowest_score++;
            min_score = scores[index];
        }
    }
    return {break_highest_score,break_lowest_score};
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
    vector<int> Res = breakingRecords(Arr);

    for (int i:Res)
        fo << i << " ";
    return 0;
}