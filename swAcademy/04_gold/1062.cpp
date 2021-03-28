// 아직 푸는중....

#include <iostream>
using namespace std;
int n, k, ans = 0;
bool alpha[26] = {0,};
string str[50];

void solve(int temp, int idx)
{
    if(temp == k - 5)
    {
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            int cc = 0;
            
            for(int j = 0; j < str[i].size(); j++)
            {
                if(alpha[str[i][j] - 'a'] == 1) cc++;

                else break;
            }

            if(cc == str[i].size()) cnt++;
        }

        if(ans < cnt) 
            ans = cnt;

        return;
    }

    for (int i = idx; i < 26; i++)
    {
        if(alpha[i] == 0)
        {
            alpha[i] = 1;
            solve(temp+1, i+1);
            alpha[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    
    if(n < 5)
    {
        cout << 0 << "\n";
        return 0;
    }

    if(n >= 26)
    {
        cout << n << "\n";
        return 0;
    }
    
    alpha['a' - 'a'] = 1;
    alpha['n' - 'a'] = 1;
    alpha['t' - 'a'] = 1;
    alpha['i' - 'a'] = 1;
    alpha['c' - 'a'] = 1;
    
    for(int i = 0; i < n; i++)
        cin >> str[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < str[i].size(); j++)
        {
            if(str[i][j] == 'a' || str[i][j] == 'n' || str[i][j] == 't' || str[i][j] == 'i' || str[i][j] == 'c')
                continue;

            alpha[str[i][j] - 'a'] = 1;
        }

    solve(0, 0);

    cout << ans << "\n";

    return 0;
}
