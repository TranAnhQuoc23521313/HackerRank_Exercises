#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> InputMaTrixVector(int &);

int birthdayCakeCandles(vector<int> candles)
{
    //Find the tallest candles in the cake
    long max = candles[0];
    for (int i = 0; i < candles.size();i++)
        if (max < candles[i])
            max = candles[i];
    //Count the tallest candles in the cake
    int count = 0;
    for (int i = 0; i < candles.size();i++)
        if (candles[i]==max)
            count++;
    return count;
}

int main()
{
    int n;
    vector<int> a = InputMaTrixVector(n);
    
    return 0;
}

vector<int> InputMaTrixVector(int &n)
{
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}