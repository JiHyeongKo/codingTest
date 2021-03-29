#include <iostream>
#include <vector>
using namespace std;
int n;
int maxPay = 0;
vector <pair<int, int>> v;

void dfs(int idx, int day, int pay)
{
    if(day > n) return;

    if(day == n)
    {
        maxPay = max(pay, maxPay);
        return;
    }

    dfs(idx+v[idx].first, day+v[idx].first, pay+v[idx].second);
    dfs(idx+1, day+1, pay);
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int day, pay;
        cin >> day >> pay;

        v.push_back({day, pay});
    }

    dfs(0, 0, 0);

    cout << maxPay << "\n";

    return 0;
}
