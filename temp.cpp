#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
    int sum_bills = 0;
    for (int i = 0; i < bill.size(); i++)
        if (i != k)
            sum_bills += bill[i];
    //cout << sum_bills << endl;
    int splited_bill = sum_bills / 2;
    if (splited_bill != b)
        cout << abs(splited_bill-b);
    if (splited_bill == b)
        cout << "Bon Appetit";
}


int main() {
    int n,k;
    int charged;
    vector<int> Bill_Detail;
    ifstream fi("input.inp");
    fi >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int value;
        fi >> value;
        Bill_Detail.push_back(value);
    }
    fi >> charged;
    //ofstream fo("output.out");
    bonAppetit(Bill_Detail,k,charged);

    return 0;
}
