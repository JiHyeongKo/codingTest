#include <iostream>
#include <vector>
using namespace std;

int dirX[3] = {0, 1, 1};
int dirY[3] = {1, 0, 1};
int n, ans=0;
int board[17][17];
int act[3] = {0, 1, 2};

// type 0 : 가로, 1 : 세로, 2 : 대각
void recur(int x, int y, int act)
{
    int tx = x + dirX[act];
    int ty = y + dirY[act];
    
    if (tx < 1 || ty < 1 || tx > n || ty > n || board[tx][ty])
        return;

    if (act == 2 && (board[tx - 1][ty] || board[tx][ty - 1]))
        return;

    if (tx == n && ty == n)
    {
        ++ans;
        return;
    }

    if(act == 0)
    {
        recur(tx, ty, 0);
        recur(tx, ty, 2);
    }

    else if(act == 1)
    {
        recur(tx, ty, 1);
        recur(tx, ty, 2);
    }

    else
    {
        recur(tx, ty, 0);
        recur(tx, ty, 1);
        recur(tx, ty, 2);
    }
    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=n; j++)
        {
            cin >> board[i][j];
        }

    if(board[n][n] != 1)
        recur(1, 1, 0);

    cout << ans << "\n";
    return 0;
}
