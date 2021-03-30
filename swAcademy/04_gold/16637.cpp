#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int n, maxVal = INT_MIN;
char buffer;
vector <char> v;

int calc(int a, int b, char oper)
{
    if(oper == '+')
        return a+b;

    else if(oper == '-')
        return a-b;

    else
        return a*b;
}

void dfs(int idx, int val)
{
    if(idx > n-1)
    {
        maxVal = max(maxVal, val);
        return;
    }

    char oper = (idx == 0)? '+' : v[idx-1];

    if(idx + 2 < n)
    {
        int buffer = calc(v[idx] - '0', v[idx+2] - '0', v[idx+1]);
        dfs(idx+4, calc(val, buffer, oper));
    }

    dfs(idx+2, calc(val, v[idx] - '0', oper));
    
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> buffer;
        v.push_back(buffer);
    }

    dfs(0, 0);
    cout << maxVal << "\n";

    return 0;
}