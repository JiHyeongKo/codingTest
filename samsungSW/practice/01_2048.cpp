// 2048 https://www.acmicpc.net/problem/12100
#include <stdio.h>

int n, returnValue;

struct BOARD {
    int map[20][20];

    void rotate()   // 방향 돌리는 함수
    {
        int temp[20][20];

        for (int y = 0; y < n; y++) 
        {
            for (int x = 0; x < n; x++) 
            {
                temp[y][x] = map[n - x - 1][y]; // (x, y) 좌표로 생각하고... 돌린다고 생각...
            }
        }

        for (int y = 0; y < n; y++) 
        {
            for (int x = 0; x < n; x++)
            {
                map[y][x] = temp[y][x]; // 다시 매핑
            }
        }
    }

    int get_max()   // 최대 횟수 구하는 함수
    {
        int returnValue = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (returnValue < map[y][x])    // 기존값보다 새로운 값이 크면,
                {
                    returnValue = map[y][x];    // 새로운 값이 기존값을 대체
                }
            }
        }
        return returnValue;
    }

    void up()   // 위로 미는 함수
    {
        int temp[20][20];   // 최대 20 * 20

        for (int x = 0; x < n; x++)
        {
            int flag = 0, target = -1;

            for (int y = 0; y < n; y++)
            {
                if (map[y][x] == 0) // 매핑이 없으면 무시
                {
                    continue;
                }

                if (flag == 1 && map[y][x] == temp[target][x])  // flag: 한 번 값이 옮겨졌고, 맵과 템프가 값이 같으면         /////////////////// 여기부터 영상 다시보셈
                {
                    temp[target][x] *= 2, flag = 0;
                }

                else    // flag != 1 || map[y][x] != temp[target][x]
                {
                    temp[++target][x] = map[y][x], flag = 1;
                }
            }

            for (++target; target < n; target++)
            {
                temp[target][x] = 0;
            }
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                map[y][x] = temp[y][x];
            }
        }
    }
};

void dfs(BOARD cur, int count) 
{
    if (count == 5) 
    {
        int candi = cur.get_max();
        if (returnValue < candi) 
        {
            returnValue = candi;
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        BOARD next = cur;
        next.up();
        dfs(next, count + 1);
        cur.rotate();
    }
}

int main()
{
    BOARD board;
    scanf("%d", &n);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%d", &board.map[y][x]);
        }
    }

    returnValue = 0;
    dfs(board, 0);
    printf("%d\n", returnValue);

    return 0;
}
