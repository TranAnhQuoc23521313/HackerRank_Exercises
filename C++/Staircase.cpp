#include <iostream>

using namespace std;

void Staircase(int n)
{
    int stair_level = 1;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n-stair_level;j++)
            cout << " ";
        for (int j = 1; j <= stair_level;j++)
        {
            if (j != stair_level)
                cout << "#";
            else 
                cout << "#" << endl;
        }
        stair_level++;
    }
}

int main()
{
    int n;
    cin >> n;
    Staircase(n);
    return 0;
}