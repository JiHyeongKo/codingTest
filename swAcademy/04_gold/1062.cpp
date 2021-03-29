#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector <string> s;
vector <int> v;
bool visit[26] = {0,};
int maxv, returnVal;

void dfs(int maxv)
{
    if(maxv == k - 5)
    {
        int cnt = 0;

        for(string es : s)
        {
            int fail = 0;

            for(int i = 0; i < es.size(); i++)
            {
                if(visit[es[i] - 'a'] == 0)
                {
                    fail = 1;
                    break;
                }
            }

            if(fail == 0)
                cnt++;
        }
        returnVal = max(returnVal, cnt);

        return;
    }

    int rastv = 0;

    if(!v.empty())
        rastv = v.back();

    for(int i = rastv; i < 26; i++)
    {
        if(visit[i] == 1)
            continue;

        visit[i] = 1;
        v.push_back(i);

        dfs(maxv+1);

        visit[i] = 0;
        v.pop_back();
    }
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        string sBuffer;
        cin >> sBuffer;
        s.push_back(sBuffer.substr(4, sBuffer.size() - 8));
    }    

    if(k < 5)
    {
        cout << 0 << "\n";
        return 0;
    }

    visit['a' - 'a'] = 1;
    visit['n' - 'a'] = 1;
    visit['t' - 'a'] = 1;
    visit['i' - 'a'] = 1;
    visit['c' - 'a'] = 1;

    dfs(0);
    cout << returnVal << "\n";

    return 0;
}
