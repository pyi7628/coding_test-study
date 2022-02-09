#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
long long answer = 0;
char num;
int arr[51][51];
long long calc(int r11, int c11, int r12, int c12, int r21, int c21, int r22, int c22, int r31, int c31, int r32, int c32)
{
    long long result = 1, sum = 0;
    for (int i = r11; i <= r12; i++)
    {
        for (int j = c11; j <= c12; j++)
        {
            sum += arr[i][j];
        }
    }
    result *= sum;
    sum = 0;
    for (int i = r21; i <= r22; i++)
    {
        for (int j = c21; j <= c22; j++)
        {
            sum += arr[i][j];
        }
    }
    result *= sum;
    sum = 0;
    for (int i = r31; i <= r32; i++)
    {
        for (int j = c31; j <= c32; j++)
        {
            sum += arr[i][j];
        }
    }
    result *= sum;
    return result;
}
int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &num);
            arr[i][j] = num - '0';
        }

    for (int i = 0; i < n - 2; i++)
    { // 가가가
        for (int j = i + 1; j < n - 1; j++)
        {
            answer = max(calc(0, 0, i, m - 1, i + 1, 0, j, m - 1, j + 1, 0, n - 1, m - 1), answer);
        }
    }
    for (int i = 0; i < m - 2; i++)
    { // 세세세
        for (int j = i + 1; j < m - 1; j++)
        {
            answer = max(calc(0, 0, n - 1, i, 0, i + 1, n - 1, j, 0, j + 1, n - 1, m - 1), answer);
        }
    }
    for (int i = 0; i < n - 1; i++)
    { // 가세세
        for (int j = 0; j < m - 1; j++)
        {
            answer = max(calc(0, 0, i, m - 1, i + 1, 0, n - 1, j, i + 1, j + 1, n - 1, m - 1), answer);
        }
    }
    for (int i = 1; i < n - 1; i++)
    { // 세세가
        for (int j = 0; j < m - 1; j++)
        {
            answer = max(calc(0, 0, i - 1, j, 0, j + 1, i - 1, m - 1, i, 0, n - 1, m - 1), answer);
        }
    }
    for (int i = 0; i < n - 1; i++)
    { // 세가가
        for (int j = 0; j < m - 1; j++)
        {
            answer = max(calc(0, 0, n - 1, j, 0, j + 1, i, m - 1, i + 1, j + 1, n - 1, m - 1), answer);
        }
    }
    for (int i = 0; i < n - 1; i++)
    { // 가가세
        for (int j = 1; j < m - 1; j++)
        {
            answer = max(calc(0, 0, i, j - 1, i + 1, 0, n - 1, j - 1, 0, j, n - 1, m - 1), answer);
        }
    }

    printf("%lld", answer);

    return 0;
}