#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, m;
vector<int> v1;
bool check(int num)
{
    int left = 0, right = v1.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v1[mid] == num)
            return true;
        else if (v1[mid] > num)
            right = mid - 1;
        else if (v1[mid] < num)
            left = mid + 1;
    }
    return false;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            v1.push_back(num);
        }
        sort(v1.begin(), v1.end());
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int num;
            scanf("%d", &num);
            bool result = check(num);
            if (result)
                printf("1\n");
            else
                printf("0\n");
        }
        v1.clear();
    }

    return 0;
}