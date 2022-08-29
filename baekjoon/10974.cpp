#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> v;
int check[10];
void back_tracking(int cnt)
{
    if (cnt == n)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            v.push_back(i);
            back_tracking(cnt + 1);
            check[i] = 0;
            v.pop_back();
        }
    }
}
int main()
{

    scanf("%d", &n);
    back_tracking(0);

    return 0;
}