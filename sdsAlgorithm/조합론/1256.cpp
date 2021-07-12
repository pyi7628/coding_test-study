// 다시 공부하기
#include <cstdio>
#define INF 1000000000
int cache[101][101];
int n, m, k;
char answer[201];
long getAZ(int a, int z)
{
    if (a == 0 || z == 0) //a*z==0
        return 1;
    if (cache[a][z] != 0)
        return cache[a][z];
    cache[a][z] = getAZ(a - 1, z) + getAZ(a, z - 1);
    if (cache[a][z] >= INF)
        cache[a][z] = INF;
    return cache[a][z];
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    if (getAZ(n, m) < k)
    {
        printf("-1");
        return 0;
    }
    // 가장 앞에 있는 문자열부터 채워 나간다.
    int countA = n, countZ = m; // 사용할 수 있는 문자개수
    for (int i = 0; i < n + m; i++)
    {
        //a를 쓸떄
        if (countA > 0)
        {
            int temp = getAZ(countA - 1, countZ);
            if (temp < k)
            {
                answer[i] = 'z';
                k -= temp;
                countZ--;
            }
            else
            {
                answer[i] = 'a';
                countA--;
            }
        }
        else
            answer[i] = 'z';
    }
    printf("%s", answer);
    return 0;
}