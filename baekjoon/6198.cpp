#include <cstdio>
#include <vector>
using namespace std;
int n, num;
long long answer = 0;
vector<int> v;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (v.empty())
            v.push_back(num);
        else
        {
            while (!v.empty() && v.back() <= num)
                v.pop_back();
            answer += v.size();
            v.push_back(num);
        }
    }
    printf("%lld", answer);
    return 0;
}