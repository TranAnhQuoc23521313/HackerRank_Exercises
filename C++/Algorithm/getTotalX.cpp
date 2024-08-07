#include <bits/stdc++.h>

#define NumberOfFile 1
using namespace std;

int UCLN(int a,int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int BCNN(vector<int> A)
{
    int BCNN_A = A[0];
    for (int i:A)
    {
        BCNN_A = BCNN_A*i / UCLN(BCNN_A,i);
    }
    return BCNN_A;
}

int getTotalX(vector<int> a, vector<int> b) {
    sort(b.begin(),b.end());
    int BCNN_A = BCNN(a);
    //cout << BCNN_A << endl;
    int i = 1;
    int Count = 0;
    while (BCNN_A*i <= b[0])
    {
        //cout << BCNN_A*i << endl;
        bool Check = true;
        for (int value:b)
        {
            //cout << BCNN_A*i << " ! " << endl;
            if ((value % (BCNN_A*i)) != 0)
            {
                //cout << BCNN_A*i << " ! " << endl;
                Check = false;
                break;
            }
        }
        if (Check)
        {
            //cout << BCNN_A*i << "Nhan" << endl;
            Count++;
        }
        i++;
    }
    return Count;
}

int main()
{
    ifstream fi("input.inp");
    int n_vector_a, n_vector_b;
    fi >> n_vector_a >> n_vector_b;
    vector<int> A,B;
    for (int i = 0; i < n_vector_a; i++)
    {
        int value;
        fi >> value;
        A.push_back(value);
    }

    for (int i = 0; i < n_vector_b; i++)
    {
        int value;
        fi >> value;
        B.push_back(value);
    }

    ofstream fo("output.out");
    fo << getTotalX(A,B);
    return 0;
}