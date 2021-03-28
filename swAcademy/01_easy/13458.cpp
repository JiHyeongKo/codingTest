#include <iostream>
using namespace std;

int main()
{
    int n, b, c;
    long long total = 0;
    cin >> n;   // 시험장 수
    
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];   // 각 시험장 응시자 수

    cin >> b >> c;  // b: 총감독관이 한 시험장에서 감시할 수 있는 인원, c: 부감독관이 한 시험장에서 감시할 수 있는 인원

    for(int i = 0; i < n; i++)
    {
        a[i] = a[i] - b;
        total++;
        
        if(a[i] > 0)
        {
            total = total + a[i] / c;
        
            if(a[i]%c > 0)
                total++;
        }
    }

    cout << total << "\n";

    return 0;
}