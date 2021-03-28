#include <iostream>
#include <cmath>
#include <cstring>
// fail
using namespace std;
int dirY[] = {1, 0, -1, 0};
int dirX[] = {0, -1, 0, 1};
typedef struct line{
    long long sx; // 작은 x
    long long sy; // 작은 y
    long long ex; // 큰 x
    long long ey; // 큰 y
    bool vect;  // 방향 0 가로, 1 세로
}line;

int didMeet(line *prev, line *cur)
{
    if(prev->sx > prev->ex)
    swap(prev->sx, prev->ex);
    
    if(prev->sy > prev->ey)
    swap(prev->sy, prev->ey);

    long long tempSX = min(cur->sx, cur->ex);
    long long tempEX = max(cur->sx, cur->ex);
    long long tempSY = min(cur->sy, cur->ey);
    long long tempEY = max(cur->sy, cur->ey);

    if(prev->vect == 0 && cur->vect == 0)   // 둘 다 가로줄
    {
        if (prev->ey != tempEY)
            return 0;

        if ((tempEX < prev->sx) || (tempSX > prev->ex))
            return 0;

        return 1;
    }

    else if (prev->vect == 0 && cur->vect == 1) // 이전거만 가로줄
    {
        if ((prev->ex < tempEX) || (prev->sx > tempEX))
            return 0;

        if (tempSY > prev->ey || tempEY < prev->sy)
            return 0;

        return 2;
    }

    else if (prev->vect == 1 && cur->vect == 0) // 현재거만 가로줄
    {
        if ((prev->ex < tempSX) || (prev->sx > tempEX))
            return 0;

        if (tempSY > prev->ey || tempEY < prev->sy)
            return 0;

        return 3;
    }

    else if (prev->vect == 1 && cur->vect == 1) // 모두 세로줄
    {
        if (prev->ex != tempEX)
            return 0;

        if ((tempEY < prev->sy) || (tempSY > prev->ey))
            return 0;

        return 4;
    }

    return 0;
}

int main()
{
    long long l;
    int n;
    long long total = 0;

    cin >> l >> n;

    int time[n];
    char order[n];
    line wall[n];
    int dir = 3; // 초기방향
    long long curY = l, curX =l;    // 초기위치
    
    for(int i = 0; i < n; i++)
    {
        cin >> time[i] >> order[i];
    }

    for(int i = 0; i < n; i++)
    {
        long long nextY = curY + time[i] * dirY[dir];
        long long nextX = curX + time[i] * dirX[dir];

        line cur;
        cur.sx = curX;
        cur.ex = nextX;
        cur.sy = curY;
        cur.ey = nextY;
        cur.vect = (curX == nextX)? 1:0;
        memcpy(&wall[i], &cur, sizeof(line));

        if(i > 1)
        for(int j = 0; j < i-1; j++) // 몸이랑 부딪힘
        {   
            int result = didMeet(&wall[j], &cur);
            
            if(result == 0)
                continue;

            else if(result == 1)
            {
                if(nextX <= wall[j].ex)
                    total = total + abs(wall[j].ex - curX);

                else
                    total = total + abs(curX - wall[j].sx);
            }

            else if (result == 2)
            {  
                total = total + abs(wall[j].ey - curY);
            }

            else if (result == 3)
            {
                total = total + abs(wall[j].ex - curX);
            }

            else if (result == 4)
            {
                if (nextY <= wall[j].ey)
                    total = total + abs(wall[j].ey - curY);

                else
                    total = total + abs(curY - wall[j].sy);
            }

            cout << total << "\n";
            return 0;
        }

        if (nextY < 0 || nextY > 2 * l || nextX < 0 || nextX > 2 * l) // 벽이랑 부딪힘
        {
            if (nextY < 0)
                total = total + curY + 1;

            else if (nextY > 2 * l)
                total = total + 2 * l - curY + 1;

            else if (nextX < 0)
                total = total + curX + 1;

            else if (nextX > 2 * l)
                total = total + 2 * l - curX + 1;

            cout << total << "\n";
            return 0;
        }

        total = time[i] + total;
        curY = nextY;
        curX = nextX;

        if (order[i] == 'L')
        {
            if(dir == 0)
            dir = 3;

            else
            dir--;
        }

        else if (order[i] == 'R')
        {
            if (dir == 3)
                dir = 0;

            else
                dir++;
        }
    }

    if(dir == 0)    // 남
        total = total + 2*l - curY + 1;

    else if (dir == 1)  // 서
        total = total + curX + 1;

    else if (dir == 2)  // 북
        total = total + curY + 1;

    else if (dir == 3)  // 동
        total = total + 2 * l - curX + 1;

    cout << total << "\n";
    return 0;
}
