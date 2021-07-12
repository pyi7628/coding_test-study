#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int nums[100] = {0};
int cnt[100][80000] = {0};
int cnt_sum[80000] = {0};
bool check[1000001];
vector<int> prime;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (check[i])
            continue;
        for (int j = i + i; j <= 1000000; j += i)
        {
            check[j] = true;
        }
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (!check[i])
            prime.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        for (int j = 0; j < prime.size(); j++)
        {
            while (num % prime[j] == 0)
            {
                cnt[i][j]++;
                cnt_sum[j]++;
                num /= prime[j];
            }
        }
    }
    int answer = 1, answer_cnt = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        if (cnt_sum[i] > 0)
        {
            printf("prime: %d cnt: %d\n", prime[i], cnt_sum[i]);
            int div = cnt_sum[i] / n;
            int namu = cnt_sum[i] % n;

            if (div == 0)
                continue;
            answer *= pow(prime[i], div);
            answer_cnt -= namu;

            // printf("asnwer: %d", answer)
            for (int j = 0; j < n; j++)
            {
                int minu = cnt[j][i] - div;
                if (minu > 0)
                    answer_cnt += minu;
            }
        }
    }
    printf("ans %d %d", answer, answer_cnt);

    return 0;
}

// #include <cstdio>
// #include <vector>
// using namespace std;
// int nums[100] = {0};
// int cnt[100][80000] = {0};
// int cnt_sum[80000] = {0};
// bool check[1000000];
// vector<int> prime;
// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     else
//         return gcd(b, a % b);
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &nums[i]);
//     }
//     for (int i = 2; i <= 1000000; i++)
//     {
//         if (check[i])
//             continue;
//         for (int j = i + i; j <= 1000000; j += i)
//         {
//             check[j] = true;
//         }
//     }
//     for (int i = 2; i <= 1000000; i++)
//     {
//         if (!check[i])
//             prime.push_back(i);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int num = nums[i];
//         for (int j = 0; j < prime.size(); j++)
//         {
//             while (num % prime[j] == 0)
//             {
//                 cnt[i][j]++;
//                 cnt_sum[j]++;
//                 num /= prime[j];
//             }
//         }
//     }
//     int answer = 1, answer_cnt = 0;
//     for (int i = 0; i <= prime.size(); i++)
//     {
//         if (cnt_sum[i] > 0)
//         {
//             printf("prime: %d cnt: %d\n", i, cnt_sum[i]);
//             int div = cnt_sum[i] / n;
//             if (div != 0)
//                 answer *= div * prime[i];
//             // printf("asnwer: %d", answer)
//             for (int j = 0; j < n; j++)
//             {
//                 int minu = cnt[j][i] - div;
//                 if (minu > 0)
//                     answer_cnt += minu;
//             }
//         }
//     }
//     //if(answer == 1)
//     printf("ans %d %d", answer, answer_cnt);

//     return 0;
// }