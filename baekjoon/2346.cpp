#include <cstdio>
#include <vector>
using namespace std;
bool check[1001];
vector<int> v;
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }

    int ptr = 0;
    int rotate = v[ptr];
    check[ptr] = true;
    printf("1 ");

    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        while (rotate != cnt)
        {
            if (rotate < 0)
            {
                ptr--;
                if (ptr == -1)
                    ptr = n - 1;
                if (!check[ptr])
                    cnt--;
            }
            else if (rotate > 0)
            {
                ptr++;
                if (ptr == n)
                    ptr = 0;
                if (!check[ptr])
                    cnt++;
            }
        }
        check[ptr] = true;
        rotate = v[ptr];
        printf("%d ", ptr + 1);
    }

    return 0;
}