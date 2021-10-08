#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, num;
vector<int> a;
vector<int> b;
vector<int> answer;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a.push_back(num);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        b.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
            answer.push_back(b[j++]);
        else
            answer.push_back(a[i++]);
    }
    while (i < a.size())
        answer.push_back(a[i++]);
    while (j < b.size())
        answer.push_back(b[j++]);
    for (int k = 0; k < answer.size(); k++)
        printf("%d ", answer[k]);

    return 0;
}