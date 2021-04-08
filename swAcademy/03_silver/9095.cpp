#include <iostream>
using namespace std;
int arr[11];

int main()
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i = 4; i < 11; i++)
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

    int n;
    cin >> n;

    while(n--)
    {
        int k;
        cin >> k;
        cout << arr[k] << "\n";
    }

    return 0;
} 