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

int workbook(int n, int k, vector<int> arr) 
{
    int page = 1;
    int count = 0;
    //map<int,vector<int>> book;
    for (int i = 0; i < n;i++)
    {
        int count_problem = 0;
        //vector<int> group_chapter;
        for (int problem = 1; problem <= arr[i];problem++)
        {
            cout << "PAGE " << page << ": Problem " << problem << endl;
            count_problem++;
            if (problem == page)
            {
                //cout << "Special Problem " << problem << endl;
                count++;
            }
            //group_chapter.push_back(problem);
            if (count_problem == k)
            {
                //book[page]=group_chapter;
                page++;
                count_problem = 0;
                //group_chapter.clear();
            }
        }
        if (arr[i]%k!=0)
            page++;
    }
    return count;
}

int main()
{
    int n,k;
    ifstream fi("input.inp");
    fi >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n;i++) 
    {
        int x;
        fi >> x;
        arr.push_back(x);
    }
    ofstream fo("output.out");
    fo << workbook(n,k,arr);
    return 0;
}