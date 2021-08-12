#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int pos[52];
bool check[52];

int main()
{
    int answer = 0;
    int pop_cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        pos[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int rotate = 0;
        int num;
        scanf("%d", &num);
        answer += min(pos[num - 1], n - pop_cnt - pos[num - 1]);
        check[num - 1] = true;
        pop_cnt++;

        for (int j = 0, ptr_cnt = 0; j < n - pop_cnt; ptr_cnt++)
        {
            int ptr = (num + ptr_cnt) % n;
            if (!check[ptr])
            {
                pos[ptr] = j;
                j++;
            }
        }
    }
    printf("%d", answer);
    return 0;
}