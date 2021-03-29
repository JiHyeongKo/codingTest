#include<iostream>
#include<vector>
using namespace std;

int N, home[17][17], ans=0;
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
vector<int> action[3] = { {0,2}, {1,2}, {0,1,2} };

// type 0 : 가로, 1 : 세로, 2 : 대각
void recur(int x, int y, int type)
{
	for (auto &t : action[type])
	{
		int tx = x + dx[t];
		int ty = y + dy[t];

		if (tx < 1 || ty < 1 || tx > N || ty > N || home[tx][ty])
			continue;

		if (t == 2 && (home[tx - 1][ty] || home[tx][ty - 1]))
			continue;

		if (tx == N && ty == N)
		{
			++ans;
			continue;
		}

		recur(tx, ty, t);
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> home[i][j];

	if(!home[N][N]) 
        recur(1, 2, 0);

	cout << ans;
	return 0;
}
