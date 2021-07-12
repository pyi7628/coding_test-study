#include <cstdio>
using namespace std;
int n, k;
// int main()
// {
//     scanf("%d %d", &n, &k);
//     int answer = 1;
//     for (int i = n; i >= n - k + 1; i--)
//     {
//         answer *= i;
//     }
//     for (int i = 1; i <= k; i++)
//     {
//         answer /= i;
//     }
//     printf("%d", answer);
//     return 0;
// }

// 또 다른 방법
int main()
{
    scanf("%d %d", &n, &k);
    //if(k==0) printf()
    int answer = 1;
    for (int i = n; i >= n - k + 1; i--)
    {
        answer *= i;
    }
    for (int i = 1; i <= k; i++)
    {
        answer /= i;
    }
    printf("%d", answer);
    return 0;
}