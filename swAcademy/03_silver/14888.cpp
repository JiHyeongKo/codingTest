#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> v;
int oper[4] = {0,};
bool visit[100];
int maxVal = -1000000001;
int minVal = 1000000001;

void dfs(int plus, int minus, int multiply, int divide, int idx, int val)
{
    if(idx == n)
    {
        maxVal = max(maxVal, val);
        minVal = min(minVal, val);
    }

    if(plus > 0)
        dfs(plus-1, minus, multiply, divide, idx+1, val+v[idx]);

    if(minus > 0)
        dfs(plus, minus-1, multiply, divide, idx+1, val-v[idx]);

    if(multiply > 0)
        dfs(plus, minus, multiply-1, divide, idx+1, val*v[idx]);
    
    if(divide > 0)
        dfs(plus, minus, multiply, divide-1, idx+1, val/v[idx]);
}


int main()
{
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        int buffer;
        cin >> buffer;

        v.push_back(buffer);
    }

    for(int i = 0; i<4; i++)
    {
        cin >> oper[i];
    }

    dfs(oper[0], oper[1], oper[2], oper[3], 1, v.front());
    cout << maxVal << "\n" << minVal << "\n";

    return 0;
}
