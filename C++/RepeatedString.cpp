#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long repeatedString(string s, long long n) 
{
    long count_a = 0;
    for (char h:s)
        if(h=='a')
            count_a++;
    if (count_a == 0)
        return 0;
    int n_s = s.length();
    //cout << "n = " << n << endl;
    long long multiple = n/n_s;
    long long count = count_a*multiple;
    long long surplus = n%n_s;
    //cout << surplus << endl;
    for (int i = 0; i < surplus;i++)
        {
            //cout << s[i];
            if (s[i]=='a')
            count++;
        }
    //cout << n_repeat << endl;
    //cout << 168329872486/count << endl;
    return count;
}

int main()
{
    string h;
    cin >> h;
    long long n;
    cin >> n;
    cout << repeatedString(h,n);
    return 0;
}