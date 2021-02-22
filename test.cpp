/* 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10828
#define MAX 20000

int pos = 0;
int dataArr[MAX] = { 0, };

int push(int data)
{
	if (pos < MAX)
	{
		dataArr[pos++] = data;
		return pos;
	}

	else
		return -1;
}

void pop()
{
	if (pos > 0)
	{
		cout << dataArr[--pos] << "\n";
	}

	else
		cout << -1 << "\n";

	return;
}

void size()
{
	cout << pos << "\n";
	return;
}

void empty()
{
	if (pos == 0)
		cout << 1 << "\n";

	else
		cout << 0 << "\n";

	return;
}

void top()
{
	if (pos != 0)
		cout << dataArr[pos-1] << "\n";

	else
		cout << -1 << "\n";

	return;
}

int main()
{
	int n = 0;
	cin >> n;

	while (n--)
	{
		string OP;
		cin >> OP;

		if (OP == "push")
		{
			int number = 0;
			cin >> number;

			push(number);
		}

		else if (OP == "top")
		{
			top();
		}

		else if (OP == "size")
		{
			size();
		}

		else if (OP == "empty")
		{
			empty();
		}

		else	// pop
		{
			pop();
		}
	}

	return 0;
}

*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10773

unsigned int totalMoney = 0;
stack<int> S;

int main()
{
	int k = 0;
	cin >> k;

	while (k--)
	{
		int num;
		cin >> num;

		if (num != 0)
			S.push(num);

		else
			S.pop();
	}

	while (!S.empty())
	{
		totalMoney = totalMoney + S.top();
		S.pop();
	}

	cout << totalMoney;

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10845

#define MAX_SIZE 20000
int dataArr[MAX_SIZE] = { 0, };
int head = -1;
int tail = -1;

int push(int data)
{
	if ((head + 1 % MAX_SIZE) != tail)
	{
		dataArr[++head % MAX_SIZE] = data;
		return head;
	}

	else
		return -1;
}

void pop()
{
	if (head != tail)
	{
		cout << dataArr[(++tail) % MAX_SIZE] << "\n";
	}

	else
		cout << -1 << "\n";
}

void size()
{
	if (head >= tail)
		cout << head - tail << "\n";

	else
		cout << tail - head + MAX_SIZE << "\n";
}

void empty()
{
	if (head == tail)
		cout << 1 << "\n";

	else
		cout << 0 << "\n";
}

void front()
{
	if (head != tail)
		cout << dataArr[(tail+1) % MAX_SIZE] << "\n";

	else
		cout << -1 << "\n";
}

void back()
{
	if (head != tail)
		cout << dataArr[(head) % MAX_SIZE] << "\n";

	else
		cout << -1 << "\n";
}

int main()
{
	int order = 0;
	cin >> order;

	while (order--)
	{
		string OP;
		cin >> OP;

		if (OP == "push")
		{
			int data;
			cin >> data;

			push(data);
		}

		else if (OP == "front")
		{
			front();
		}

		else if (OP == "back")
		{
			back();
		}

		else if (OP == "size")
		{
			size();
		}

		else if (OP == "pop")
		{
			pop();
		}

		else	// empty
		{
			empty();
		}
	}
	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10866

int main()
{
	deque<int> DQ;

	int order = 0;
	cin >> order;

	while (order--)
	{
		string OP;
		cin >> OP;

		if (OP == "push_front")
		{
			int number;
			cin >> number;

			DQ.push_front(number);
		}

		else if (OP == "push_back")
		{
			int number;
			cin >> number;

			DQ.push_back(number);
		}

		else if (OP == "pop_front")
		{
			if (!DQ.empty())
			{
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}

			else
				cout << -1 << "\n";
		}

		else if (OP == "pop_back")
		{
			if (!DQ.empty())
			{
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}

			else
				cout << -1 << "\n";
		}

		else if (OP == "size")
		{
			cout << DQ.size() << "\n";
		}

		else if (OP == "empty")
		{
			cout << DQ.empty() << "\n";
		}

		else if (OP == "front")
		{
			if (!DQ.empty())
			{
				cout << DQ.front() << "\n";
			}

			else
				cout << -1 << "\n";
		}

		else	// back
		{
			if (!DQ.empty())
			{
				cout << DQ.back() << "\n";
			}

			else
				cout << -1 << "\n";
		}
	}

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/4949

int main()
{
	while (1)
	{
		stack<char> S;
		int fail = 0;
		string str;
		getline(cin, str);

		if (str == ".")
			break;

		for (auto c : str)
		{
			if (c == '(' || c == '[')
				S.push(c);

			else if (c == ')')
			{
				if (!S.empty() && S.top() == '(')
					S.pop();
				
				else
				{
					fail = 1;
					break;
				}
			}

			else if (c == ']')
			{
				if (!S.empty() && S.top() == '[')
					S.pop();

				else
				{
					fail = 1;
					break;
				}
			}

			else if (c == '.')
				break;
		}

		if (!S.empty() || fail == 1)
			cout << "no" << "\n";

		else
			cout << "yes" << "\n";
	}

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2504

int main()
{
	int sum = 0;
	int total = 1;
	int fail = 0;

	char str[32];
	cin >> str;
	stack<char> S;

	for (int i = 0; i<strlen(str); i++)
	{
		char c = str[i];

		if (c == '(' || c == '[')
		{
			S.push(c);

			if (c == '(')
				total = total * 2;

			else
				total = total * 3;
		}

		else if (c == ')')
		{
			if (!S.empty() && S.top() == '(')
			{
				if (i >= 1 && str[i - 1] == '(')	// �ٷ� �տ��� �����ѰŸ�
					sum = sum + total;	// ���ϰ�

				S.pop();	// ����
				total = total / 2;	// ���� ������
			}

			else
			{
				fail = 1;
				break;
			}
		}

		else if (c == ']')
		{
			if (!S.empty() && S.top() == '[')
			{
				if (i >= 1 && str[i - 1] == '[')	// �ٷ� �տ��� �����ѰŸ�
					sum = sum + total;	// ���ϰ�

				S.pop();	// ����
				total = total / 3;	// ���� ������
			}

			else
			{
				fail = 1;
				break;
			}
		}
	}

	if (!S.empty() || fail == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

	cout << sum << "\n";

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10799

int main()
{
	stack<char> S;
	string str;
	getline(cin, str);
	int total = 0;
	char prev = 0;

	for (auto c : str)
	{
		if (c == '(')
			S.push(c);

		else
		{
			if(!S.empty())
				S.pop();

			if (prev == ')')
				total = total + 1;
			
			else
				total = total + S.size();
		}

		prev = c;
	}

	cout << total;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1926

int directionY[4] = { -1, 1, 0, 0 };
int directionX[4] = { 0, 0, -1, 1 };
int vis[501][501];
int board[501][501];

int main()
{
	int num = 0;
	int area = 0;
	int maxArea = 0;
	int n, m;

	cin >> n >> m;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];
		}

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			if (board[y][x] == 0 || vis[y][x] == 1) continue;

			num++;
			area = 0;

			queue<pair<int, int>> Q;
			vis[y][x] = 1;
			Q.push({ y,x });

			while (!Q.empty())
			{
				area++;

				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nextY = cur.first + directionY[dir];
					int nextX = cur.second + directionX[dir];

					if (board[nextY][nextX] == 0 || vis[nextY][nextX] == 1) continue;
					if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

					vis[nextY][nextX] = 1;
					Q.push({ nextY, nextX });
				}

				maxArea = max(area, maxArea);
			}
		}

	cout << num << "\n";
	cout << maxArea << "\n";

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2178

int main()
{
	int directionY[4] = { -1, 1, 0, 0 };
	int directionX[4] = { 0, 0, -1, 1 };
	int dist[101][101];
	char board[101][101];
	int n, m;

	cin >> n >> m;
	
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			dist[y][x] = 0;
	
	for(int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> board[y][x];

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			if (board[y][x] == '0' || dist[y][x] != 0)
				continue;

			queue<pair<int, int>> Q;
			Q.push({ y,x });

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nextY = cur.first + directionY[dir];
					int nextX = cur.second + directionX[dir];

					if (board[nextY][nextX] == '0' || dist[nextY][nextX] > 0) continue;
					if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

					dist[nextY][nextX] = dist[cur.first][cur.second] + 1;
					Q.push({ nextY, nextX });
				}
			}
		}

	cout << dist[n - 1][m - 1] + 1;

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/7576
int directionY[4] = { -1, 1, 0, 0 };
int directionX[4] = { 0, 0, -1, 1 };
int day = 0;
int board[1001][1001];
int vis[1001][1001];

int main()
{
	queue<pair<int, int>> Q;

	int n, m;
	cin >> m >> n;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			board[y][x] = 0;
			vis[y][x] = 0;
		}

	for(int y = 0; y<n; y++)
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];

			if (board[y][x] == 1)
				Q.push({ y,x });
		}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nextY = cur.first + directionY[dir];
			int nextX = cur.second + directionX[dir];

			if (board[nextY][nextX] != 0 || vis[nextY][nextX] != 0) continue;
			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

			vis[nextY][nextX] = vis[cur.first][cur.second] + 1;
			Q.push({ nextY, nextX });
		}
	}

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			if (board[y][x] == 0 && vis[y][x] == 0)
			{
				cout << -1;
				return 0;
			}

			day = max(day, vis[y][x]);
		}

	cout << day;

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/4179 ��ƴ�,,,,,,,,,,,,,,,,,,,,,,

char mapping[1002][1002] = { 0, };
int FD[1002][1002];
int JD[1002][1002];
queue<pair<int, int>> JQ, FQ;

int main()
{
	int directionY[4] = { -1, 1, 0, 0 };
	int directionX[4] = { 0, 0, -1, 1 };

	int r, c;
	cin >> c >> r;

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
		{
			FD[i][j] = -1;
			JD[i][j] = -1;
		}

	for (int y = 0; y < c; y++)
		for (int x = 0; x < r; x++)
		{
			cin >> mapping[y][x];

			if (mapping[y][x] == 'J')
			{
				JQ.push({ y,x });
				JD[y][x] = 0;
			}
			if (mapping[y][x] == 'F')
			{
				FQ.push({ y,x });
				FD[y][x] = 0;
			}
		}

	while (!FQ.empty())
	{
		auto curF = FQ.front();
		FQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nextFY = curF.first + directionY[dir];
			int nextFX = curF.second + directionX[dir];

			if (nextFY < 0 || nextFY >= c || nextFX < 0 || nextFX >= r) continue;
			if (FD[nextFY][nextFX] >= 0 || mapping[nextFY][nextFX] == '#') continue;

			FD[nextFY][nextFX] = FD[curF.first][curF.second] + 1;
			FQ.push({ nextFY, nextFX });
		}
	}

	while (!JQ.empty())
	{
		auto curJ = JQ.front();
		JQ.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nextJY = curJ.first + directionY[dir];
			int nextJX = curJ.second + directionX[dir];

			if (nextJY < 0 || nextJY >= c || nextJX < 0 || nextJX >= r)
			{
				cout << JD[curJ.first][curJ.second] + 1;
				return 0;
			}

			if (JD[nextJY][nextJX] >= 0 || mapping[nextJY][nextJX] == '#') continue;
			if (FD[nextJY][nextJX] != -1 && FD[nextJY][nextJX] <= (JD[curJ.first][curJ.second] + 1)) continue;

			JD[nextJY][nextJX] = JD[curJ.first][curJ.second] + 1;
			JQ.push({ nextJY, nextJX });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1697

int vis[100000] = { 0, };

int main()
{
	queue<int> Q;
	int su, young;
	int nextS = 0;
	int order = 0;

	cin >> su >> young;

	Q.push(su);

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
	
		if (cur == young)
		{
			order = vis[cur];
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				nextS = cur + 1;
			}

			else if (i == 1)
			{
				nextS = cur - 1;
			}

			else
			{
				nextS = cur * 2;
			}

			if (nextS < 0 || nextS > 100000) continue;
			if (vis[nextS] > 0) continue;
			
			Q.push(nextS);
			vis[nextS] = vis[cur] + 1;
		}
	}

	cout << order;

	return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1260 ��ƴ�,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

bool connected[1002][1002] = { 0, };
int n, m, v;
bool visit1[1002];
bool visit2[1002];

int dfs(int v)
{
	stack<int> S;
	S.push(v);
	visit1[v] = 1;
	cout << v << " ";

	while (!S.empty())
	{
		for (int i = 1; i <= n; i++)
		{
			if (visit1[i] == 0 && connected[v][i] == 1)
			{
				S.push(i);
				visit1[i] = 1;

				v = S.top();

				i = 0;

				cout << v << " ";
			}
		}

		if (visit1[v] == 1)
		{
			S.pop();

			if (!S.empty())
				v = S.top();
		}
	}

	cout << "\n";
	return 0;
}

int bfs(int v)
{
	queue<int> Q;
	Q.push(v);
	visit2[v] = 1;
	cout << v << " ";

	while (!Q.empty())
	{
		for (int i = 1; i <= n; i++)
		{
			if (visit2[i] == 0 && connected[v][i] == 1)
			{
				Q.push(i);
				visit2[i] = 1;
				cout << i << " ";
			}
		}

		if (visit2[v] == 1)
		{
			Q.pop();

			if (!Q.empty())
				v = Q.front();
			
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int p1, p2;
		cin >> p1 >> p2;

		connected[p1][p2] = 1;
		connected[p2][p1] = 1;
	}

	dfs(v);
	bfs(v);

	return 0;
}

*/

/*
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/1629

long long a, b, n;	// overflow ���� int ��� long long ����ؾ���!!!!!!!!!!!!!!

long long recursive(long long a, long long b, long long n)
{
	if (b == 1)
		return a % n;

	long long val = recursive(a, b / 2, n);
	val = val * val % n;    // ���Ⱑ Ű ����Ʈ..

	if (b % 2 == 1)    // Ȧ����
		val = (val * a) % n;

	return val;
}

int main()
{
	cin >> a >> b >> n;
	cout << recursive(a, b, n) << "\n";

	return 0;
}
*/

/*
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/11729

int a, b, n;

void hanoi(int a, int b, int n)
{
	if (n == 0)
		return;

	hanoi(a, 6-a-b, n - 1);
	cout << a << " " << b << "\n";
	hanoi(6-a-b, b, n - 1);
}

int main()
{
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(1, 3, n);
}
*/

/*
#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1074
int n, r, c;

int func(int n, int r, int c)
{
	if (n == 0)
		return 0;

	int val = 1 << (n-1);

	if (r < val && c < val)
		return val*val + func(n-1, r, c);

	else if (r < val && c >= val)
		return val*val + func(n-1, r, c);

	else if (r >= val && c < val)
		return 2*val*val + func(n-1, r, c);

	else if (r >= val && c >= val)
		return 3*val*val + func(n-1, r, c);
}

int main()
{
	cin >> n >> r >> c;

	cout << func(n, r, c) << "\n";

}
*/

/*
#include <iostream>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/15649
int arr[10];
bool isused[10];

void func(int k, int n, int m)
{
	if(k == m)
	{
		for(int i = 0; i < m; i++)
		cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for(int i = 1; i<=n; i++)
	{
		if(!isused[i])
		{
			arr[k] = i;
			isused[i] = 1;
			func(k+1, n, m);
			isused[i] = 0;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	func(0, n, m);
}
*/

#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/9663

bool dirOne[20];	/* 세로 */
bool dirTwo[20];	/* 대각선 */
bool dirThree[20];	/* 대각선 \ */ 
int cnt = 0;
int n;

void func(int k)
{
	if(k == n)
	{
		cnt++;
		return;
	}

	for(int i = 0; i<n; i++)
	{
		if(dirOne[i] || dirTwo[i+k] || dirThree[i - k + n - 1])
			continue;

		dirOne[i] = 1;
		dirTwo[i+k] = 1;
		dirThree[i - k + n - 1] = 1;
		func(k+1);
		dirOne[i] = 0;
		dirTwo[i+k] = 0;
		dirThree[i - k + n - 1] = 0;
	}
}

int main()
{
	cin >> n;
	func(0);
	
	cout << cnt <<"\n";
	return 0;
}

// https://www.acmicpc.net/problem/1182