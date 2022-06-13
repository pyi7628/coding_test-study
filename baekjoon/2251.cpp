// #include <cstdio>
// #include <queue>

// using namespace std;

// struct NODE
// {
//     int bottles[3];
// };

// bool check[201][201][201];
// bool result[201];
// queue<NODE> q;

// int limits[3];

// int a, b, c;
// NODE temp;

// int main()
// {
//     scanf("%d%d%d", &limits[0], &limits[1], &limits[2]);

//     temp.bottles[0] = 0, temp.bottles[1] = 0, temp.bottles[2] = limits[2];
//     check[0][0][limits[2]] = true;
//     q.push(temp);

//     while (!q.empty())
//     {
//         NODE cur = q.front();
//         q.pop();

//         if (cur.bottles[0] == 0)
//         {
//             result[cur.bottles[2]] = true;
//         }

//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (i != j)
//                 {
//                     temp.bottles[0] = cur.bottles[0], temp.bottles[1] = cur.bottles[1], temp.bottles[2] = cur.bottles[2];
//                     temp.bottles[j] += cur.bottles[i] > limits[j] - cur.bottles[j] ? limits[j] - cur.bottles[j] : cur.bottles[i];
//                     temp.bottles[i] -= cur.bottles[i] > limits[j] - cur.bottles[j] ? limits[j] - cur.bottles[j] : cur.bottles[i];

//                     if (!check[temp.bottles[0]][temp.bottles[1]][temp.bottles[2]])
//                     {
//                         check[temp.bottles[0]][temp.bottles[1]][temp.bottles[2]] = true;
//                         q.push(temp);
//                     }
//                 }
//             }
//         }
//     }

//     for (int i = 0; i <= 200; i++)
//     {
//         if (result[i])
//             printf("%d ", i);
//     }

//     return 0;
// }

#include <cstdio>
#include <queue>

using namespace std;

struct NODE
{
    int bottles[3];
};

bool check[201][3];
bool result[201];
queue<NODE> q;

int limits[3];

int a, b, c;
NODE temp;

int main()
{
    scanf("%d%d%d", &limits[0], &limits[1], &limits[2]);

    temp.bottles[0] = 0, temp.bottles[1] = 0, temp.bottles[2] = limits[2];
    check[0][0] = true, check[0][1] = true, check[limits[2]][2] = true;
    q.push(temp);

    while (!q.empty())
    {
        NODE cur = q.front();
        q.pop();

        if (cur.bottles[0] == 0)
            result[cur.bottles[2]] = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    temp.bottles[0] = cur.bottles[0], temp.bottles[1] = cur.bottles[1], temp.bottles[2] = cur.bottles[2];
                    temp.bottles[j] += cur.bottles[i] > limits[j] - cur.bottles[j] ? limits[j] - cur.bottles[j] : cur.bottles[i];
                    temp.bottles[i] -= cur.bottles[i] > limits[j] - cur.bottles[j] ? limits[j] - cur.bottles[j] : cur.bottles[i];

                    if (!(check[temp.bottles[0]][0] && check[temp.bottles[1]][1] && check[temp.bottles[2]][2]))
                    {
                        check[temp.bottles[0]][0] = true, check[temp.bottles[1]][1] = true, check[temp.bottles[2]][2] = true;
                        q.push(temp);
                    }
                }
            }
        }
    }

    for (int i = 0; i <= 200; i++)
    {
        if (result[i])
            printf("%d ", i);
    }

    return 0;
}