// #include <cstdio>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int h, w, s = 501, sv = 0, ev = 0, e = 0, sum = 0;
// int arr[501];
// vector<int> v;
// int main()
// {
//     scanf("%d%d", &h, &w);
//     for (int i = 0; i < w; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     // s = arr[0];
//     for (int i = 1; i < w; i++)
//     {
//         while (i < w && (arr[i - 1] > arr[i] && sv < arr[i - 1]) || (arr[i - 1] <= arr[i] && sv < arr[i]))
//         {
//             s = i - 1;
//             sv = arr[i - 1];
//             i++;
//         }
//         while (i < w && i > s && arr[i - 1] <= arr[i] && ev < arr[i])
//         {
//             e = i;
//             ev = arr[i];
//             i++;
//         }

//         if (e > s)
//         {
//             // printf("test s:%d e:%d\n", s, e);
//             for (int j = s + 1; j < e; j++)
//             {
//                 sum += (min(arr[s], arr[e]) - arr[j]);
//                 // printf("test sum:%d %d %d\n", sum, arr[e], arr[j]);
//             }
//             s = e;
//             sv = ev, ev = 0;
//         }
//         // else if (e <= s)
//         //     s = e, sv = ev, ev = 0;
//     }
//     printf("%d", sum);
//     return 0;
// }

// #include <cstdio>
// #include <algorithm>
// #include <vector>
// using namespace std;
// typedef pair<int, int> pii;
// int h, w, s = 501, sv = 0, ev = 0, e = 0, sum = 0;
// int arr[501];
// vector<pii> v;
// int main()
// {
//     scanf("%d%d", &h, &w);
//     for (int i = 0; i < w; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     if (w > 2 && arr[0] > arr[1])
//         v.push_back(make_pair(arr[0], 0));
//     for (int i = 1; i < w - 1; i++)
//     {

//         if ((arr[i - 1] <= arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] < arr[i] && arr[i] >= arr[i + 1]))
//         {
//             v.push_back(make_pair(arr[i], i));
//         }
//         // else if (e <= s)
//         //     s = e, sv = ev, ev = 0;
//     }
//     if (w > 2 && arr[w - 1] > arr[w - 2])
//         v.push_back(make_pair(arr[w - 1], w - 1));

//     // printf("size: %d\n", v.size());
//     if (v.size() >= 2)
//         for (int i = 1; i < v.size(); i++)
//         {
//             s = v[i - 1].second, sv = v[i - 1].first;
//             e = v[i].second, ev = v[i].first;
//             // printf("test s:%d e:%d\n", s, e);
//             for (int j = s + 1; j < e; j++)
//             {
//                 sum += (min(arr[s], arr[e]) - arr[j]);
//                 // printf("test sum:%d %d %d\n", sum, arr[e], arr[j]);
//             }
//         }

//     printf("%d", sum);
//     return 0;
// }
