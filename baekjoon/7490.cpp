#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<char> v;
int t, n;

void back_tracking()
{
    if (v.size() >= n)
        return;

    if (v.size() == n - 1)
    {
        char op = '+';
        int sum = 0;
        int acc = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == ' ')
                acc = acc * 10 + (i + 2);
            else
            {
                if (op == '+')
                    sum += acc, acc = i + 2;
                else if (op == '-')
                    sum -= acc, acc = i + 2;
                op = v[i];
            }
        }
        if (op == '+')
            sum += acc;
        else if (op == '-')
            sum -= acc;
        if (sum == 0)
        {
            for (int i = 0; i < v.size(); i++)
            {
                printf("%d%c", i + 1, v[i]);
            }
            printf("%d\n", n);
        }
        return;
    }
    v.push_back(' ');
    back_tracking();
    v.pop_back();
    v.push_back('+');
    back_tracking();
    v.pop_back();
    v.push_back('-');
    back_tracking();
    v.pop_back();
}
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        back_tracking();
        v.clear();
        printf("\n");
    }
    return 0;
}