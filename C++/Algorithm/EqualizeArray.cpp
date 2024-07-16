#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> InputMaTrixVector(int &);

int equalizeArray(vector<int> arr) 
{
    //Sort the arr that upper.
    sort(arr.begin(),arr.end());

    /*Create 2 vector k and count
k consist of the amount of the element of arr[i]
count is the shorten vector of k*/
    vector<int> k(101,0);
    vector<int> count;

    //Count the amount of arr[i]
    for (int& i:arr)
        k[i]++;
    //Shorten vector k
    for (int& i:k)
        if (i>0)
            count.push_back(i);

    //Result is the arr size minus max of vector count.
    return arr.size()-*max_element(count.begin(),count.end());
}

int main()
{
    int n;
    vector<int> a = InputMaTrixVector(n);
    cout << equalizeArray(a);
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