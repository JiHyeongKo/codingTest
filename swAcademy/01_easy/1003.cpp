#include <iostream>
using namespace std;

int main()
{
    int T, n;
    int arr[41] = {0, 1, 1};
    for(int i = 3; i < 41; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cin >> T;

    while(T--)
    {
        cin >> n;

        if(n == 0)
            cout << 1 << " " << 0 << "\n";

        else if (n==1)
            cout << 0 << " " << 1 << "\n";

        else
            cout << arr[n-1] << " " << arr[n] << "\n";
    }

    return 0;
}