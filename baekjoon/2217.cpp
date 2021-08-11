#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
int answer = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < v.size(); i++)
    {
        if (answer < v[i] * (i + 1))
            answer = v[i] * (i + 1);
        }
    printf("%d", answer);
    return 0;
}