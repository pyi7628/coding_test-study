// #include <vector>
// #include <stdio.h>
// #include <iostream>
// #include <queue>

// using namespace std;

// int to_num(char arr[])
// {
//     int res = 0;
//     for (int i = 0; arr[i]; i++)
//     {
//         res *= 10;
//         res += arr[i] - '0';
//     }
//     return res;
// }

// int conv(int num, int l, int r)
// {
//     char buf[16];
//     sprintf(buf, "%d", num);
//     char temp;
//     temp = buf[l];
//     buf[l] = buf[r];
//     buf[r] = temp;

//     // 맨 앞자리가 0이 되는 것 아닌ㄴ지 확인
//     if (buf[0] == '0')
//         return 0;
//     return to_num(buf);
// }

// bool is_ok(int num)
// {
//     // 예외 처리
//     if (num < 10)
//         return false;
//     if (num < 100 && num % 10 == 0)
//         return false;
//     return true;
// }

// int get_num_len(int num)
// {
//     int len = 0;
//     while (num > 0)
//     {
//         len++;
//         num /= 10;
//     }
//     return len;
// }

// int check[1000000] = {0};
// int main()
// {
//     // 완전 탐색 방법
//     // 예외가 되는 것 바로처리 : 1000000=> 바로 답/ 9, 8.. => 교환이 안됨/ 10, 20.. => 교환이 안됨
//     queue<int> q;
//     int n, k;
//     scanf("%d%d", &n, &k);
//     if (n == 1000000)
//     {
//         printf("%d", n);
//         return 0;
//     }
//     if (!is_ok(n))
//     {
//         printf("-1");
//         return 0;
//     }

//     q.push(n);
//     for (int i = 0; i < k; i++)
//     {
//         // 단계별로 처리하기 위해서
//         // 다음번 작업전에 임시로 저장하는 역할
//         // q size로 처리하면 이렇게 처리할 필요가 없긴함!
//         // 아 이거 현 시점에 q에 들어간 것만 처리하고 그 이후에 생긴애들을 나중에 처리하기 위함임, q하나로도 짤 수 있음
//         vector<int> next_q;
//         while (!q.empty())
//         {
//             int cur = q.front();
//             q.pop();

//             int len = get_num_len(cur);

//             for (int s = 0; s < len; s++)
//             {
//                 for (int e = s + 1; e < len; e++)
//                 {
//                     int next_num = conv(cur, s, e);
//                     if (next_num == 0)
//                         continue;

//                     // 중복 처리 해야한다!
//                     next_q.push_back(next_num);
//                 }
//             }
//         }
//         for (int j = 0; j < next_q.size(); j++)
//         {
//             q.push(next_q[i]);

//             // q에 교환한 결과를 넣는다
//             // 이때 중복되는 것은 visit 또는 map을 이용하여 해결한다.
//         }
//     }
//     int ans = 0;
//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();
//         if (ans < cur)
//             ans = cur;
//     }

//     printf("%d\n", ans);
//     return 0;
// }

// #include <cstdio>
// #include <vector>
// #include <queue>
// using namespace std;

// int tonum(char arr[])
// {
//     int res = 0;
//     for (int i = 0; arr[i]; i++)
//     {
//         res *= 10;
//         res += arr[i] - '0';
//     }
//     return res;
// }

// int conv(int num, int l, int r)
// {
//     // l과 r의 체크가 안되어있음
//     // 처음에 num의 자리수는 정해져있기때문에 그걸 이용하면  됨
//     // arr
//     char buf[16];
//     sprintf(buf, "%d", num);
//     char tmp;
//     // swap
//     tmp = buf[l];
//     buf[l] = buf[r];
//     buf[r] = tmp;
//     // 앞자리가 0이 아닌지 체크도..
//     if (buf[0] == '0')
//         return 0;
//     return tonum(buf);
// }

// int n, k;

// bool isok(int num)
// {
//     // 예외가 되는 것들은 바로처리
//     // 1 ~ 9 ==> 교환이 안됨 ==> -1
//     if (num < 10)
//         return false;
//     // 10, 20, .. .90 ==> 교환이 안됨 ==> -1
//     if (num < 100 && num % 10 == 0)
//         return false;
//     return true;
// }

// int get_num_len(int num)
// {
//     int len = 0;
//     while (num > 0)
//     {
//         len++;
//         num /= 10;
//     }
//     return len;
// }
// struct ST
// {
//     vector<int> c;
// };

// int check[1000000] = {0};

// int main()
// {
//     scanf("%d%d", &n, &k);
//     if (n == 1000000)
//     {
//         printf("%d", n);
//         return 0;
//     }
//     if (!isok(n))
//     {
//         printf("-1");
//         return 0;
//     }

//     queue<int> q;
//     queue<int> temp_q;
//     vector<ST> v;
//     // int arr[12][200] = {
//     //     0,
//     // };
//     int i = 0;
//     for (i = 0; i < k; i++)
//     {
//         ST t;
//         v.push_back(t);
//     }
//     q.push(n);
//     int max_odd = 0;
//     int max_even = 0;
//     for (int i = 0; i < k; i++)
//     {
//         // q --> next_q --> q
//         // 단계별로 처리하기 위해서
//         // 다음번 작업을 하기전에 임시로 저장하는 곳이고
//         // q size를 이용해서 어찌어찌 처리를 하면 필요가 없어요 ==> 고민해보시면 됨
//         vector<int> next_q;

//         int cnt[12] = {
//             0,
//         };

//         while (!q.empty())
//         {
//             int cur = q.front();
//             q.pop();
//             int len = get_num_len(cur);
//             for (int s = 0; s < len; s++)
//             {
//                 for (int e = s + 1; e < len; e++)
//                 {
//                     int next_num = conv(cur, s, e);
//                     if (next_num == 0)
//                         continue;
//                     // 꼭 다 넣어야할까????
//                     // 현재 다음번 처리는 "중복"이 발생하고 있습니다
//                     // 적절하게 처리해 중복을 피해봅시다
//                     if (next_num == 654321)
//                         printf("check k: %d\n", i);
//                     if (check[next_num] == 0)
//                     {
//                         if (i % 2 == 0 && max_even < next_num)
//                             max_even = next_num;
//                         else if (i % 2 == 1 && max_odd < next_num)
//                             max_odd = next_num;
//                         printf("in k: %d\n", i);
//                         check[next_num] = i + 1;
//                         next_q.push_back(next_num);
//                         v[i].c.push_back(next_num);
//                     }
//                 }
//             }
//         }
//         if (next_q.size() == 0)
//         {
//             break;
//             // int ans = 0;
//             // // while (!temp_q.empty())
//             // // {
//             // //     int cur = temp_q.front();
//             // //     temp_q.pop();
//             // //     if (ans < cur)
//             // //         ans = cur;
//             // // }

//             // for (int j = 0; i - 2 >= 0 && j < v[i - 2].c.size(); j++)
//             // {
//             //     printf("size0 i: %d j: %d val: %d\n", i, j, v[i - 2].c[j]);
//             //     if (ans < v[i - 2].c[j])
//             //         ans = v[i - 2].c[j];
//             // }
//             // if (i % 2 != 0)
//             //     ans = max_even;
//             // else
//             //     ans = max_odd;
//             // printf("mid %d i: %d", ans, i);
//             // //printf("mid %d", ans);
//             // return 0;
//         }
//         // else
//         //     while (!temp_q.empty())
//         //         temp_q.pop();

//         for (int i = 0; i < next_q.size(); i++)
//         {
//             q.push(next_q[i]);
//             // temp_q.push(next_q[i]);
//         }
//     }
//     // k번을 돌렸기 때문에 q에남아 있는 것들은 k번을 수행하고 남은 숫자들이고
//     // q에 남은것 중에 가장 큰것을 출력하면 됨
//     int ans = 0;
//     // if (!q.empty())
//     // {
//     //     while (!q.empty())
//     //     {
//     //         int cur = q.front();
//     //         q.pop();
//     //         if (ans < cur)
//     //             ans = cur;
//     //     }
//     // }
//     // else
//     // {
//     if (i % 2 != 0)
//         ans = max_even;
//     else
//         ans = max_odd;
//     // }
//     printf("%d %d", ans, i);
//     return 0;
// }

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int tonum(char arr[])
{
    int res = 0;
    for (int i = 0; arr[i]; i++)
    {
        res *= 10;
        res += arr[i] - '0';
    }
    return res;
}

int conv(int num, int l, int r)
{
    char buf[16];
    sprintf(buf, "%d", num);
    char tmp;
    tmp = buf[l];
    buf[l] = buf[r];
    buf[r] = tmp;
    if (buf[0] == '0')
        return 0;
    return tonum(buf);
}

int n, k;

bool isok(int num)
{
    if (num < 10)
        return false;
    if (num < 100 && num % 10 == 0)
        return false;
    return true;
}

int get_num_len(int num)
{
    int len = 0;
    while (num > 0)
    {
        len++;
        num /= 10;
    }
    return len;
}

int check[1000000] = {0};

int main()
{
    scanf("%d%d", &n, &k);
    if (n == 1000000)
    {
        printf("%d", n);
        return 0;
    }
    if (!isok(n))
    {
        printf("-1");
        return 0;
    }

    queue<int> q;

    int i = k;

    q.push(n);
    int max_odd = 0;
    int max_even = 0;
    for (int i = 0; i < k; i++)
    {
        vector<int> next_q;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            int len = get_num_len(cur);
            for (int s = 0; s < len; s++)
            {
                for (int e = s + 1; e < len; e++)
                {
                    int next_num = conv(cur, s, e);
                    if (next_num == 0)
                        continue;

                    if (check[next_num] == 0)
                    {
                        if (i % 2 == 0 && max_even < next_num)
                            max_even = next_num;
                        else if (i % 2 == 1 && max_odd < next_num)
                            max_odd = next_num;
                        check[next_num] = i + 1;
                        next_q.push_back(next_num);
                    }
                }
            }
        }
        if (next_q.size() == 0)
            break;

        for (int i = 0; i < next_q.size(); i++)
            q.push(next_q[i]);
    }
    int ans = 0;
    if (i % 2 != 0)
        ans = max_even;
    else
        ans = max_odd;
    printf("%d %d", ans, i);
    return 0;
}
