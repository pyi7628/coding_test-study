#include <cstdio>

int n, ans = 0;
int chess[14][14];

void recur(int line)
{

    // 종료 조건
    if (line == n)
    {
        ans++;
        return;
    }
    // 해당줄 어디다가 놓을 수 있는지 탐색
    for (int i = 0; i < n; i++)
    {
        if (chess[line][i] != -1)
            continue;
        chess[line][i] = line;

        // line에 놓었으니까 상, 하,좌/우 대각선에 queen을 놓지 못하게 한다. 이떄 상, 좌/우는 확인 필요 x

        // 좌우
        for (int j = 0; j < n; j++)
        {
            if (chess[line][j] == -1)
                chess[line][j] = line;
        }
        // 하
        for (int j = line; j < n; j++)
        {
            if (chess[j][i] == -1)
                chess[j][i] = line;
        }
        // 대각선
        for (int y = line, x = i; y < n && x >= 0; y++, x--)
        {
            if (chess[y][x] == -1)
                chess[y][x] = line;
        }
        for (int y = line, x = i; y < n && x < n; y++, x++)
        {
            if (chess[y][x] == -1)
                chess[y][x] = line;
        }

        recur(line + 1);
        // 지우기!
        // 좌우
        for (int j = 0; j < n; j++)
        {
            if (chess[line][j] == line)
                chess[line][j] = -1;
        }
        // 하
        for (int j = line; j < n; j++)
        {
            if (chess[j][i] == line)
                chess[j][i] = -1;
        }
        // 대각선
        for (int y = line, x = i; y < n && x >= 0; y++, x--)
        {
            if (chess[y][x] == line)
                chess[y][x] = -1;
        }
        for (int y = line, x = i; y < n && x < n; y++, x++)
        {
            if (chess[y][x] == line)
                chess[y][x] = -1;
        }
    }
}

int main()
{
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            chess[i][j] = -1;
        }
    }

    scanf("%d", &n);
    recur(0);
    printf("%d", ans);

    return 0;
}