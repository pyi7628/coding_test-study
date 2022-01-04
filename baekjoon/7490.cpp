#include <cstdio>
#include <vector>
using namespace std;
vector<char> v;
int t, n;

void back_tracking(int cnt, int sum, char op, int acc)
{
    int next;

    if (cnt > n)
        return;
    if (cnt == n)
    {
        return;
    }

    v.push_back('+');
}
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        back_tracking(1, 0, '+', 0);
    }
    return 0;
}