#include <iostream>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/12100
int n;
int board[21][21];
int boardClone[21][21];

void rotate() // this fuction is regulated...
{
    int temp[21][21];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = boardClone[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            boardClone[i][j] = temp[n - 1 - j][i];
}

void tilt(int dir)
{
    while (dir--) // dir은 0~3이니 걍 돌린다.
        rotate();

    for (int i = 0; i < n; i++)
    {
        int tilted[21] = {
            0,
        };           // 저장할 공간.
        int idx = 0; // 저장할 위치.

        for (int j = 0; j < n; j++)
        {
            if (boardClone[i][j] == 0) // 삽입할 값이 0인 경우
                continue;

            if (tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
                tilted[idx] = boardClone[i][j];

            else if (tilted[idx] == boardClone[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
            {
                tilted[idx] = tilted[idx] * 2;
                idx++;
            }

            else // 다른 값을 갖는 블록이 충돌
            {
                idx++;
                tilted[idx] = boardClone[i][j];
            }
        }

        for (int j = 0; j < n; j++)
            boardClone[i][j] = tilted[j]; // boardClone[i]에 tilted를 덮어씀
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            boardClone[i][j] = board[i][j];

    int maxValue = 0;

    for (int tmp = 0; tmp < 1024; tmp++) // 4방향에 대해 5번 수행하니 (4^5 = 1024)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                boardClone[i][j] = board[i][j];

        int brute = tmp;

        for (int i = 0; i < 5; i++)
        {
            int dir = brute % 4;
            brute = brute / 4;
            tilt(dir);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                maxValue = max(maxValue, boardClone[i][j]);
    }

    cout << maxValue << "\n";
    return 0;
}