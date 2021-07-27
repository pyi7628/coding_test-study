#include <cstdio>
#include <vector>
using namespace std;
int n, s;
vector<int> v;
int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    int start = 0, end = 0;
    int sum = 0;
    int cnt = 100001;
    for (; end < n; end++)
    {
        // while (sum < s)
        // {
        //     sum += v[e++];
        // }
        sum += v[end];
        while (sum >= s)
        {
            sum -= v[start];
            // printf("s: %d e: %d\n", start, end);
            if (cnt > end - start + 1)
            {
                cnt = end - start + 1;
            }
            start++;
        }
    }
    if (cnt == 100001)
        printf("0");
    else
        printf("%d", cnt);
    return 0;
}