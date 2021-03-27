// 구슬탈출2 https://www.acmicpc.net/problem/13460
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct INFO
{
    int ry;
    int rx;
    int by;
    int bx;
    int count;
};

INFO start;
char map[10][11]; // 맨 마지막 NULL 저장

int bfs()
{
    const int dy[] = {-1, 1, 0, 0}; // 상하
    const int dx[] = {0, 0, -1, 1}; // 좌우

    int visited[10][10][10][10] = {
        0,
    };
    queue<INFO> q; // INFO형 큐 생성
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    int returnValue = -1; // 실패시 -1 반환

    while (!q.empty()) // q가 비어있지 않는 동안
    {
        INFO cur = q.front();
        q.pop();

        if (cur.count > 10)
            break;

        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') // red가 탈출할 시
        {
            returnValue = cur.count;
            break;
        }

        for (int dir = 0; dir < 4; dir++) // 방향
        {
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            while (1)
            {
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') // 벽이거나 구멍이 아니면
                {
                    next_ry += dy[dir], next_rx += dx[dir]; // 방향대로 이동
                }

                else
                {
                    if (map[next_ry][next_rx] == '#')           // 벽을 만나면
                        next_ry -= dy[dir], next_rx -= dx[dir]; // 한 칸 전으로 이동하고 종료

                    break;
                }
            }

            while (1)
            {
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
                    next_by += dy[dir], next_bx += dx[dir];

                else
                {
                    if (map[next_by][next_bx] == '#')
                        next_by -= dy[dir], next_bx -= dx[dir];

                    break;
                }
            }

            if (next_ry == next_by && next_rx == next_bx) // red, blue가 같은 위치일 경우
            {
                if (map[next_ry][next_rx] != 'O') // 탈출한 경우가 아니면
                {
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);  // 이동거리
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx); // 이동거리

                    if (red_dist > blue_dist) // 이동거리가 큰 게 멀리서 온 것 -> 한 칸 전으로 이동
                        next_ry -= dy[dir], next_rx -= dx[dir];

                    else
                        next_by -= dy[dir], next_bx -= dx[dir];
                }
            }

            if (visited[next_ry][next_rx][next_by][next_bx] == 0) // 방문한 곳이 아니면
            {
                visited[next_ry][next_rx][next_by][next_bx] = 1; // 방문했다 하고.
                INFO next;

                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }

    return returnValue;
}

int main()
{
    int n; // y 길이
    int m; // x 길이

    scanf("%d %d", &n, &m); // 맵 크기 지정

    for (int i = 0; i < n; i++)
        scanf("%s", map[i]); // 맵 저장

    for (int y = 0; y < n; y++) // 공 위치 저장
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 'R')
                start.ry = y, start.rx = x;

            if (map[y][x] == 'B')
                start.by = y, start.bx = x;
        }
    }
    start.count = 0;

    int returnValue = bfs();
    printf("%d\n", returnValue);

    return 0;
}