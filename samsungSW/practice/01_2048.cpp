// 2048 https://www.acmicpc.net/problem/12100
#include <stdio.h>

int n, returnValue;

struct BOARD {
    int map[20][20];

    void rotate()   // ���� ������ �Լ�
    {
        int temp[20][20];

        for (int y = 0; y < n; y++) 
        {
            for (int x = 0; x < n; x++) 
            {
                temp[y][x] = map[n - x - 1][y]; // (x, y) ��ǥ�� �����ϰ�... �����ٰ� ����...
            }
        }

        for (int y = 0; y < n; y++) 
        {
            for (int x = 0; x < n; x++)
            {
                map[y][x] = temp[y][x]; // �ٽ� ����
            }
        }
    }

    int get_max()   // �ִ� Ƚ�� ���ϴ� �Լ�
    {
        int returnValue = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (returnValue < map[y][x])    // ���������� ���ο� ���� ũ��,
                {
                    returnValue = map[y][x];    // ���ο� ���� �������� ��ü
                }
            }
        }
        return returnValue;
    }

    void up()   // ���� �̴� �Լ�
    {
        int temp[20][20];   // �ִ� 20 * 20

        for (int x = 0; x < n; x++)
        {
            int flag = 0, target = -1;

            for (int y = 0; y < n; y++)
            {
                if (map[y][x] == 0) // ������ ������ ����
                {
                    continue;
                }

                if (flag == 1 && map[y][x] == temp[target][x])  // flag: �� �� ���� �Ű�����, �ʰ� ������ ���� ������         /////////////////// ������� ���� �ٽú���
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
