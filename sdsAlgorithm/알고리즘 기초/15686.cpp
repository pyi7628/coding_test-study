// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stdlib.h>
// using namespace std;
// typedef pair<int, int> pii;
// int n, m;
// int answer = 1000000;
// bool check[13];
// int map[50][50];
// int dist_map[50][50];
// vector<pii> hv;
// vector<pii> cv;

// void calculate_dist()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             dist_map[i][j] = 120;
//         }
//     }
//     for (int i = 0; i < cv.size(); i++)
//     {
//         if (check[i] == true)
//         {
//             for (int j = 0; j < hv.size(); j++)
//             {
//                 int dist = abs(cv[i].first - hv[j].first) + abs(cv[i].second - hv[j].second);
//                 printf("i: %d dist: %d\n", i, dist);
//                 if (dist < dist_map[hv[j].first][hv[j].second])
//                     dist_map[hv[j].first][hv[j].second] = dist;
//             }
//         }
//     }
//     int temp_answer = 0;
//     for (int i = 0; i < hv.size(); i++)
//     {
//         printf("i: %d j: %d len: %d\n", hv[i].first, hv[i].second, dist_map[hv[i].first][hv[i].second]);
//         temp_answer += dist_map[hv[i].first][hv[i].second];
//     }
//     if (temp_answer < answer)
//         answer = temp_answer;
// }

// void comb(int cnt, int num)
// {
//     if (cnt == m)
//     {
//         calculate_dist();
//         return;
//     }
//     for (int i = num; i < cv.size(); i++)
//     {
//         if (!check[i])
//         {
//             check[i] = true;
//             //  cur_c.push_back(cv[i]);
//             comb(cnt + 1, i);
//             check[i] = false;
//         }
//     }
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &map[i][j]);
//             if (map[i][j] == 2)
//                 cv.push_back(make_pair(i, j));
//             else if (map[i][j] == 1)
//                 hv.push_back(make_pair(i, j));
//         }
//     }
//     comb(0, 0);
//     printf("%d", answer);

//     return 0;
// }

#include <cstdio>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int answer = 1000000;
bool check[13];
int map[50][50];
int dist_map[50][50];
vector<pii> hv;
vector<pii> cv;

void calculate_dist()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist_map[i][j] = 120;
        }
    }
    for (int i = 0; i < cv.size(); i++)
    {
        if (check[i] == true)
        {
            for (int j = 0; j < hv.size(); j++)
            {
                int dist = abs(cv[i].first - hv[j].first) + abs(cv[i].second - hv[j].second);
                if (dist < dist_map[hv[j].first][hv[j].second])
                    dist_map[hv[j].first][hv[j].second] = dist;
            }
        }
    }
    int temp_answer = 0;
    for (int i = 0; i < hv.size(); i++)
    {
        temp_answer += dist_map[hv[i].first][hv[i].second];
    }
    if (temp_answer < answer)
        answer = temp_answer;
}

void comb(int cnt, int num)
{
    if (cnt == m)
    {
        calculate_dist();
        return;
    }
    for (int i = num; i < cv.size(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            comb(cnt + 1, i);
            check[i] = false;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2)
                cv.push_back(make_pair(i, j));
            else if (map[i][j] == 1)
                hv.push_back(make_pair(i, j));
        }
    }
    comb(0, 0);
    printf("%d", answer);

    return 0;
}