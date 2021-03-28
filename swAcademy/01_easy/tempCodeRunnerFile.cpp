#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, int *zero, int *one)
{
    if (n == 0)
    {
        (*zero)++;
        return 0;
    }
    else if (n == 1)
    {
        (*one)++;
        return 1;
    }
    else
    {
        return fibonacci(n - 1, zero, one) + fibonacci(n - 2, zero, one);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <pair <int ,int>> v;
    v.push_back({1, 0});
    v.push_back({0, 1});

    while(n--)
    {
        int buffer;
    
        cin >> buffer;

        if(buffer == 0)
        {
            cout << 1 << " " << 0;
            continue;
        }

        else if(buffer == 1)
        {
            cout << 0 << " " << 1;
            continue;            
        }

        else if(buffer >= 2)
        {   
            buffer++;
            for(int i = 2; i < buffer; i++)
            {
                v.push_back({(v[i - 1].first + v[i - 2].first), (v[i - 1].second + v[i - 2].second)});
            }
        }
        
        cout << v[buffer-1].first << " " << v[buffer-1].second << "\n";
    }

    return 0;
}