#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
void find(int num)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] == num)
        {
            printf("1 ");
            return;
        }
        else if (v[mid] > num)
            right = mid - 1;
        else if (v[mid] < num)
            left = mid + 1;
    }
    printf("0 ");
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);
        find(num);
    }

    return 0;
}