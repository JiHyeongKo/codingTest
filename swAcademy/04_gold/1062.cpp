#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> s;
bool chk[26];
int N, K;
int maxv = 0;
vector<int> v;

void dfs(int num)
{
    // 5개 제외하고 모두 고를경우
    if (num == K - 5)
    {
        int cnt = 0;

        for (string es : s)
        {
            bool sw = false;
            
            for (int i = 0; i < es.size(); i++)
            {
                char ec = es[i];

                if (chk[ec - 'a'] == false)
                {
                    sw = 1;
                    break;
                }
            }
            if (sw == false)
                cnt++;
        }

        maxv = max(maxv, cnt);

        return;
    }

    // 알파벳 중복체크 후 추가
    // 조합이므로 리스트 맨 뒤에서 빼기
    int lastv = -1;
    if (!v.empty())
        lastv = v.back();

    for (int i = lastv + 1; i < 26; i++)
    {
        if (chk[i])
            continue;
        chk[i] = 1;
        v.push_back(i);

        dfs(num + 1);

        chk[i] = 0;
        v.pop_back();
    }
}

int main()
{
    for(int i = 0; i < 26; i++)
        chk[i] = 0;

    cin >> N >> K;

    // 문자열 잘라서 보관
    for (int i = 0; i < N; i++)
    {
        string es;
        cin >> es;
        // 잘라서 보관
        s.push_back(es.substr(4, es.size() - 8));
    }

    chk['a' - 'a'] = 1;
    chk['n' - 'a'] = 1;
    chk['t' - 'a'] = 1;
    chk['i' - 'a'] = 1;
    chk['c' - 'a'] = 1;

    // 5개 이하일경우 문자열 읽을 수 없음
    if (K < 5)
    {
        cout << 0 << '\n';
        return 0;
    }

    dfs(0);

    cout << maxv << '\n';

    return 0;
}
