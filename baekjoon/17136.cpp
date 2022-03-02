#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
struct NODE
{
    int r;
    int c;
    int size;
};
struct compare
{
    bool operator()(NODE a, NODE b)
    {
        if (a.size == b.size)
        {
            if (a.r == b.r)
                return a.c > b.c;
            return a.r > b.r;
        }
        return a.size < b.size;
    }
};
int map[11][11];
int paper[6] = {0, 5, 5, 5, 5, 5};
bool check[11][11];
priority_queue<NODE, vector<NODE>, compare> pq;
queue<NODE> tempq;
int answer = 100, cur_answer = 0, cnt = 0, total_cnt = 0;

NODE temp;
void check_paper(int r, int c)
{
    bool is_possible = false;
    for (int i = 1; i <= 5; i++)
    {
        is_possible = false;
        if (r + i <= 10 && c + i <= 10)
        {
            is_possible = true;
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    if (!map[r + j][c + k])
                        is_possible = false;
                }
            }
        }
        if (is_possible)
        {
            temp.r = r, temp.c = c, temp.size = i;
            pq.push(temp);
        }
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j])
                cnt++;
        }
    }
    if (cnt == 0)
    {
        printf("0");
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j])
            {
                check_paper(i, j);
            }
        }
    }
    while (!pq.empty())
    {
        NODE cur;
        cur_answer = 0;
        total_cnt = 0;
        while (!pq.empty())
        {
            bool is_possible = false;
            cur = pq.top();
            pq.pop();
            tempq.push(cur);
            //printf("\nr: %d c: %d size: %d", cur.r, cur.c, cur.size);
            if (!check[cur.r][cur.c] && paper[cur.size] > 0)
            {
                is_possible = true;
                for (int i = 0; i < cur.size; i++)
                {
                    for (int j = 0; j < cur.size; j++)
                    {
                        if (check[cur.r + i][cur.c + j])
                            is_possible = false;
                    }
                }
            }
            if (is_possible)
            {
                for (int i = 0; i < cur.size; i++)
                {
                    for (int j = 0; j < cur.size; j++)
                    {
                        check[cur.r + i][cur.c + j] = true;
                        total_cnt++;
                    }
                }
                printf("test r:%d c:%d size: %d\n", cur.r, cur.c, cur.size);
                cur_answer++;
                paper[cur.size]--;
            }
        }
        printf("\ncnt: %d total_cnt: %d\n", cnt, total_cnt);
        if (cnt == total_cnt && answer > cur_answer)
            answer = cur_answer;
        tempq.pop();
        while (!tempq.empty())
        {
            cur = tempq.front();
            tempq.pop();
            pq.push(cur);
        }
        for (int i = 1; i <= 5; i++)
            paper[i] = 5;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                check[i][j] = false;
    }
    if (answer == 100)
        answer = -1;
    printf("%d", answer);
    return 0;
}