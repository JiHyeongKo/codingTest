#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    //주사위 : 문제에 나와있는 순서대로(1,2,3,4,5,6): 1이 윗면
    int dice[6] = {0, 0, 0, 0, 0, 0};
    //동서 북남으로 움직이면 1 2 3 4 5 6위치가 각각 어떻게 바뀌는지
    //다만, index이므로 각각의 위치에서 1만큼씩 뺌
    int move_dice[4][6] = {
        {3, 1, 0, 5, 4, 2},
        {2, 1, 5, 0, 4, 3},
        {4, 0, 2, 3, 5, 1},
        {1, 5, 2, 3, 0, 4}};

    //방향 : 원위치 동서북남
    int dx[5] = {0, 0, 0, -1, 1};
    int dy[5] = {0, 1, -1, 0, 0};

    //입력
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    int board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int command[k];
    for (int i = 0; i < k; i++)
    {
        cin >> command[i];
    }

    int tmp[6];
    for (int i = 0; i < k; i++)
    {
        x = x + dx[command[i]];
        y = y + dy[command[i]];
        if ((0 <= x && x < n) && (0 <= y && y < m))
        {
            //주사위 방향 바뀌었을 때, 윗면(1)부터 아랫면(6)까지 숫자 바뀐거 저장
            for (int j = 0; j < 6; j++)
                tmp[j] = dice[j];
            for (int j = 0; j < 6; j++)
                dice[move_dice[command[i] - 1][j]] = tmp[j];

            if (board[x][y] == 0)
            {
                board[x][y] = dice[5]; //보드에 주사위 아랫면수 삽입
            }
            else
            {
                dice[5] = board[x][y]; //주사위 아랫면에 보드 수 삽입
                board[x][y] = 0;
            }

            cout << dice[0] << endl;
        }
        else
        {
            x = x - dx[command[i]];
            y = y - dy[command[i]];
        }
    }

    return 0;
}