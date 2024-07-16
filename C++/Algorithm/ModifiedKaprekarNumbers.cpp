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

int Count_Numb(int x)
{
    int temp = x;
    int dem = 0;
    while (temp != 0)
    {
        int dv = temp%10;
        dem++;
        temp/=10;
    }
    return dem;
}

bool SumBtwTwoPart(string h,int x,int digit)
{
    string left,right;
    for (int i = 0; i < h.length()-digit;i++)
        left+=h[i];
    for (int i = h.length()-digit; i < h.length();i++)
        right+=h[i];
    //cout << "l = " << left << " r = " << right << endl;
    long long sum = stoi(left)+stoi(right);
    //cout << "Sum = " << sum << endl;
    if (sum == x)
        return true;
    return false;
}

void kaprekarNumbers(long p, long q) 
{
    bool Check = false;
    for (long i = p; i <= q;i++)
    {
        if (i==1)
            cout << i << " ";
        long long kaprekar_numb = pow(i,2);
        //cout << "square is " << pow(i,2) << endl;
        if (kaprekar_numb > 10)
        {
            int digit = Count_Numb(i);
            string kaprekar_string = to_string(kaprekar_numb);
            if (SumBtwTwoPart(kaprekar_string,i,digit))
                {
                    cout << i << " ";
                    Check = true;
                }
        }
    }
    if (!(Check))
        cout << "INVALID RANGE";
}

int main()
{
    long p,q;
    ifstream fi("input.inp");
    fi >> p >> q;
    ofstream fo("output.out");
    kaprekarNumbers(p,q);
    fo << 3/2;
    return 0;
}