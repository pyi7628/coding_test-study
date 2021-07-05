#include <cstdio>
#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

int sorting(int a, int b)
{
    return a > b;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < 26; i++)
    {
        v.push_back(0);
    }

    for (int i = 0; i < n; i++)
    {
        char str[10];
        scanf("%s", str);
        for (int j = 0; j < strlen(str); j++)
        {
            v[str[j] - 'A'] += pow(10, strlen(str) - j - 1);
        }
    }
    sort(v.begin(), v.end(), sorting);
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int temp = (v[i] * (9 - i));
        sum += temp;
    }
    printf("%d", sum);
    return 0;
}