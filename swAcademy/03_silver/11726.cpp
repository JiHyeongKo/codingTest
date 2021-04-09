#include <iostream>
using namespace std;
int s[1005];

int main()
{
    int n;
    cin >> n;

    s[1] = 1;
    s[2] = 2;
    
    if(n <= 2)
    {
        cout << s[n] << "\n";
        return 0;
    }

    for(int i = 3; i <= n; i++)
    {
        s[i] = (s[i-1] + s[i-2])%10007;
    }

    cout << s[n] << "\n";
    return 0;
}