#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> InputMaTrixVector(int &);

void plusMinus(vector<int> arr) 
{
    int n = arr.size();
    int count_positive_numbers = 0;
    int count_negative_numbers = 0;
    int zero_numbers = 0;
    for (int i = 0; i < arr.size();i++)
    {
        if (arr[i] > 0)
            count_positive_numbers++;
        if (arr[i] < 0)
            count_negative_numbers++;
        if (arr[i]==0)
            zero_numbers++;
    }
    //cout << count_positive_numbers << " " << count_negative_numbers << " " << zero_numbers << endl;
    setprecision(6);
    cout << fixed << count_positive_numbers/(float)n << endl;
    cout << count_negative_numbers/(float)n << endl;
    cout << zero_numbers/(float)n;
}

int main()
{
    int n;
    vector<int> a = InputMaTrixVector(n);
    plusMinus(a);
    return 0;
}

vector<int> InputMaTrixVector(int &n)
{
    vector<int> arr;
    cin >> n;
    for (int j = 0; j < n;j++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}