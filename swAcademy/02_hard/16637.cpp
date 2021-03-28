#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int N;
string s;
int result = INT_MIN;

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}

    return 0;
}

void func(int idx, int value)
{
    if (idx >= N)
    {
        result = max(result, value);
        return;
    }

    char op = idx >= 1 ? s[idx - 1] : '+';
    int temp = calculate(value, s[idx] - '0', op);

    func(idx + 2, temp);

    if (idx < N - 2)
    {
        temp = calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
        temp = calculate(value, temp, op);
        func(idx + 4, temp);
    }
}

int main(void)
{
    cin >> N;
    cin >> s;

    func(0, 0);
    cout << result << "\n";
    return 0;
}
