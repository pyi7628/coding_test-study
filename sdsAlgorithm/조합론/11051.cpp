#include <cstdio>
//다리놓기랑 비슷
int cache[1001][1001];
int nCr(int n, int r)
{
    if (r == 0)
        return 1;
    if (n < r || n < 0 || 1000 < n || r < 0 || 1000 < r)
        return 0;
    if (cache[n][r] != 0)
        return cache[n][r];
    int temp = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % 10007;
    cache[n][r] = temp;
    return cache[n][r];
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", nCr(n, k));
}