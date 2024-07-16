#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<vector<int>> InputMaTrixVector(int &,int&,int&,int&);

int TheDirection(int r_q,int c_q,int n,map<pair<int,int>,int> P,int dx,int dy)
{
    int x = r_q + dx;
    int y = c_q + dy;
    int count=0;
    if (abs(dy)==1 && dx == 0) // Follow Oy up if dy > 0 and reverse
    {
        if (dy == 1)
        {
            while (y > c_q && y <= n)
            {
                if (P[{x,y}])
                    return count;
                cout << "(" << x << "," << y << ")" << endl;
                count++;
                y++;
            }
        }
        if (dy == -1)
        {
            while (y < c_q && y >= 1)
            {
                if (P[{x,y}])
                    return count;
                cout << "(" << x << "," << y << ")" << endl;
                count++;
                y--;
            }
        }
    }
    if (dx == 1)
    {
        while (x > r_q && x <= n)
        {
            if (P[{x,y}])
                return count;
            cout << "(" << x << "," << y << ")" << endl;
            count++;
            x++;
        }
    }
    if (dx == -1)
    {
        while (x < r_q && x >= 1)
        {
            if (P[{x,y}])
                return count;
            cout << "(" << x << "," << y << ")" << endl;
            count++;
            x--;
        }
    }
    return count;
}

int ThePart_Direction(int r_q,int c_q,int n,map<pair<int,int>,int> P,int Part)
{
    //Direction[dx,dy]
    int count=0;
    int x = r_q;
    int y = c_q;
    vector<vector<int>> direction = {{0,0},{1,1},{-1,1},{-1,-1},{1,-1}};
    int dx = direction[Part][0];
    int dy = direction[Part][1];
    while (x+dx <= n && x+dx >=1 && y+dy <= n && y+dy >=1)
    {
        if (P[{x+dx,y+dy}])
            return count;
        count++;
        x+=dx;
        y+=dy;
        cout << "(" << x << "," << y << ")" << endl;
    }
    return count;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) 
{
    //cout << endl;
    int count = 0;
    //vector<vector<int>> direction = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
    map<pair<int,int>,int> P;
    for (auto& x:obstacles)
        P[{x[0],x[1]}]=1;
    //Go up
    int x = r_q;
    int y = c_q;
    count = TheDirection(x,y,n,P,0,1) 
    +TheDirection(x,y,n,P,0,-1) 
    +TheDirection(x,y,n,P,1,0) 
    +TheDirection(x,y,n,P,-1,0) 
    +ThePart_Direction(x,y,n,P,1) + ThePart_Direction(x,y,n,P,2) + ThePart_Direction(x,y,n,P,3)+ThePart_Direction(x,y,n,P,4);
    return count;
}

int main()
{
    int n,k,r_q,c_q;
    vector<vector<int>> a = InputMaTrixVector(n,k,r_q,c_q);
    cout << queensAttack(n,k,r_q,c_q,a);
    return 0;
}

vector<vector<int>> InputMaTrixVector(int &n,int &k,int&r_q,int&c_q)
{
    vector<vector<int>> arr;
    cin >> n >> k;
    cin >> r_q >> c_q;
    for (int i = 0; i < k;i++)
    {
        vector<int> hang;
        for (int j = 0; j < 2;j++)
        {
            int x;
            cin >> x;
            hang.push_back(x);
        }
        arr.push_back(hang);
    }
    return arr;
}