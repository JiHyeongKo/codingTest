#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v;
    int minimum, maximum, sum = 0;
    cin >> minimum >> maximum;

    for(int i = minimum; i <= maximum; i++)
    {
        int j = 2;
        for(j = 2; j< i; j++)
        {
            if((i%j) == 0)
                break;
        }

        if(j == i)
            v.push_back(i);
        
    }

    for(int i = 0; i < v.size(); i++)
        sum = sum + v[i];

    if(!v.empty())
        cout << sum << "\n" << v[0] << "\n";

    else
        cout << -1 << "\n";

    return 0;
}