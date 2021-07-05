#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct WATER_POS
{
    int row;
    int col;
    int step;
};
struct POSITION
{
    int row;
    int col;
    int step;
};

int main()
{
    char map[52][52];
    char water_map[52][52];
    int water_cnt[52][52] = {
        0,
    };
    int visit[52][52] = {
        0,
    };
    int R, C;
    int rot[5][3] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int answer = -1;

    queue<POSITION> q;
    queue<WATER_POS> water;

    scanf("%d %d", &R, &C);
    getchar();

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%c", &map[i][j]);

            water_map[i][j] = map[i][j];
            if (map[i][j] == 'S')
            {
                visit[i][j] = 1;
                POSITION p;
                p.row = i;
                p.col = j;
                p.step = 0;
                q.push(p);
                water_map[i][j] = '.';
            }
            else if (map[i][j] == '*')
            {
                WATER_POS w;
                w.row = i;
                w.col = j;
                w.step = 0;
                water.push(w);
            }
        }
        getchar();
    }
    int water_step = 0;

    while (!water.empty())
    {
        WATER_POS cur = water.front();
        water.pop();
        for (int i = 0; i < 4; i++)
        {
            int temp_r = cur.row + rot[i][0];
            int temp_c = cur.col + rot[i][1];
            if (temp_r < R && temp_c < C && temp_r >= 0 && temp_c >= 0 && water_map[temp_r][temp_c] == '.' && water_cnt[temp_r][temp_c] == 0)
            {
                water_map[temp_r][temp_c] = '*';
                water_cnt[temp_r][temp_c] = cur.step + 1;
                WATER_POS w;
                w.row = temp_r;
                w.col = temp_c;
                w.step = cur.step + 1; // 여따 저장할 필요 없긴 하ㅏ넹
                water.push(w);
                // printf("test: %c\n", water_map[temp_r][temp_c]);
            }
        }
    }

    while (!q.empty())
    {
        POSITION cur = q.front();
        q.pop();
        if (map[cur.row][cur.col] == 'D')
        {
            answer = cur.step;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int temp_r = cur.row + rot[i][0];
            int temp_c = cur.col + rot[i][1];
            // if (temp_c == 0 && temp_r == 0)
            //     printf("test: %d\n", water_cnt[0][0]);
            if (temp_r < R && temp_c < C && temp_r >= 0 && temp_c >= 0 && map[temp_r][temp_c] != 'X' && map[temp_r][temp_c] != '*' && (water_cnt[temp_r][temp_c] > cur.step + 1 || water_cnt[temp_r][temp_c] == 0) && visit[temp_r][temp_c] == 0)
            {
                visit[temp_r][temp_c] = 1;
                POSITION p;
                WATER_POS w;
                p.row = temp_r;
                p.col = temp_c;
                p.step = cur.step + 1; // 여따 저장할 필요 없긴 하ㅏ넹
                q.push(p);
                // printf("\n ori: ( %d, %d ) step: %d pos: ( %d, %d )\n", cur.row, cur.col, cur.step + 1, temp_r, temp_c);
            }
        }
    }
    if (answer == -1)
        printf("KAKTUS\n");
    else
        printf("%d\n", answer);
    return 0;
}

// 큐하나로 하는거 생각한 방법도 한번 해보기