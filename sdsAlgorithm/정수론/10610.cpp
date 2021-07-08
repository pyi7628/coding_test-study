#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
char s[100001];
int sum = 0;
int has0 = 0;
int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '0')
            has0 = 1;
        sum += s[i] - '0';
        nums.push_back(s[i] - '0');
    }
    if (sum % 3 != 0 || !has0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            printf("%d", nums[i]);
        }
    }

    return 0;
}