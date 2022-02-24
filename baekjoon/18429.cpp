#include <cstdio>
using namespace std;
int answer, n, k, total = 500;
int kits[8];
bool check[8];
void back_tracking(int cnt)
{
    if (total - (cnt * k) < 500)
        return;
    if (cnt == n)
    {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            total += kits[i];
            back_tracking(cnt + 1);
            total -= kits[i];
            check[i] = false;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &kits[i]);
    }
    back_tracking(0);
    printf("%d", answer);
    return 0;
}