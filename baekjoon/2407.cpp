#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string dp[101][101];
string add(string n1, string n2)
{
    int sum = 0;
    string result;
    while (!n1.empty() || !n2.empty() || sum != 0)
    {
        if (!n1.empty())
            sum += n1.back() - '0', n1.pop_back();
        if (!n2.empty())
            sum += n2.back() - '0', n2.pop_back();
        result.push_back(sum % 10 + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}
string nCm(int n, int m)
{
    if (m == 0)
        return "1";
    else if (n < m || n < 0 || m < 0)
        return "0";
    if (dp[n][m] != "")
        return dp[n][m];
    string temp = add(nCm(n - 1, m - 1), nCm(n - 1, m));
    dp[n][m] = temp;
    return temp;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%s", nCm(n, m).c_str());
    return 0;
}