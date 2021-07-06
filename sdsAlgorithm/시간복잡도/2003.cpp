#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    vector<int> v;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        scanf("%d", &num);
        v.push_back(num);
    }

    int answer = 0;

    // 완전 탐색 비슷하게
    // 이때까지 더했던거를 이용하자!
    // for (int s = 0; s < n; s++)
    // {
    //     int sum = 0;
    //     for (int e = s; e < n; e++)
    //     {
    //         sum += v[e];
    //         if (sum == m)
    //         {
    //             answer++;
    //             break;
    //         }
    //         else if (sum > m)
    //         {
    //             break;
    //         }
    //     }
    // }

    //투포인터
    // int s = 0, e = 0;
    // int sum = 0;
    // for (; s < n && e < n;)
    // {
    //     for (; e < n; e++)
    //     {

    //         sum += v[e];
    //         if (sum == m)
    //         {
    //             answer++;
    //             e++;
    //             break;
    //         }
    //         else if (sum > m)
    //         {
    //             e++;
    //             break;
    //         }
    //     }

    //     while (sum >= m && s < n)
    //     {
    //         sum -= v[s];
    //         s++;
    //         if (sum == m)
    //             answer++;
    //     }
    // }

    //정리 투포인터
    int sum = 0;
    for (int s = 0, e = 0; e < n; e++)
    {
        sum += v[e];
        while (sum > m)
        {
            sum -= v[s];
            s++;
        }

        if (sum == m)
            answer++;
    }

    printf("%d", answer);
    return 0;
}