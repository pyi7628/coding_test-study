//내가 푼거 아님 다시 공부하기
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[8], answer[8];
bool used[8];
// 맵으로 문자열 썼는지 확인할 수도 ㅣㅇㅆ음
int recur(int k)
{

    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", answer[i]);
        }
        printf("\n");
    }
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        if (prev != a[i])
        {
            used[i] = true;
            answer[k] = a[i];
            prev = a[i];
            recur(k + 1);
            used[i] = false;
        }
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    recur(0);
    return 0;
}