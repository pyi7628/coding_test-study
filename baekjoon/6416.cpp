// #include <cstdio>
// #include <vector>
// #include <string.h>
// using namespace std;
// int u, v, k = 1, flag = 0;
// int p[100000];
// bool check[100000];
// vector<int> vec;
// // 부모가 있으면 .. 일단 안된다, 근데 루트는 어떡하징? -> 고냥 마지막에 검사하지뭥
// int main()
// {
//     while (1)
//     {
//         scanf("%d%d", &u, &v);
//         if (u == 0 && v == 0)
//         {
//             int cnt = 0;
//             for (int i = 0; i < vec.size(); i++)
//             {
//                 if (!check[vec[i]] && p[vec[i]] == 0)
//                     cnt++;
//                 check[vec[i]] = true;
//             }

//             if (cnt == 1 && !flag)
//                 printf("Case %d is a tree.\n", k);
//             else
//                 printf("Case %d is not a tree.\n", k);
//             k++;
//             flag = 0;
//             memset(p, 0, sizeof(p));
//             memset(check, 0, sizeof(check));
//             continue;
//         }
//         if (u < 0 && v < 0)
//             return 0;
//         if (p[v] != 0 || v == u)
//             flag = 1;
//         else
//             p[v] = u;
//         vec.push_back(u);
//     }
//     return 0;
// }

#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
int u, v, k = 1, flag = 0;
int p[100000];
bool check[100000];
vector<int> vec;
// 부모가 있으면 .. 일단 안된다, 근데 루트는 어떡하징? -> 고냥 마지막에 검사하지뭥

int find(int num)
{
    if (p[num] == num)
        return num;
    return p[num] = find(p[num]);
}
int main()
{
    for (int i = 0; i < 100000; i++)
    {
        p[i] = i;
    }
    while (1)
    {
        scanf("%d%d", &u, &v);
        if (u == 0 && v == 0)
        {
            int cnt = vec.size() == 0 ? 1 : 0;
            for (int i = 0; i < vec.size(); i++)
            {
                if (!check[vec[i]] && p[vec[i]] == vec[i])
                    cnt++;
                check[vec[i]] = true;
            }

            if (cnt == 1 && !flag)
                printf("Case %d is a tree.\n", k);
            else
                printf("Case %d is not a tree.\n", k);
            k++;
            flag = 0;
            for (int i = 0; i < 100000; i++)
            {
                p[i] = i;
            }
            vec.clear();
            memset(check, 0, sizeof(check));
            continue;
        }
        if (u < 0 && v < 0)
            return 0;
        int p1 = find(u), p2 = find(v);
        if (p1 == p2)
            flag = 1;
        else
            p[p2] = p1;
        vec.push_back(u);
        vec.push_back(v);
    }
    return 0;
}