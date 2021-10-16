#include <cstdio>
#include <cmath>
using namespace std;
int check[16]; // index row에 어디에 뒀는지 check
int answer = 0, n;
bool pruning(int r, int c)
{
    for (int i = 0; i < r; i++)
        if (check[i] == c || abs(i - r) == abs(check[i] - c))
            return false;
    return true;
}
void back_tracking(int r)
{
    if (r == n)
    {
        answer++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (pruning(r, i))
        {
            check[r] = i;
            back_tracking(r + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    back_tracking(0);
    printf("%d", answer);
    return 0;
}