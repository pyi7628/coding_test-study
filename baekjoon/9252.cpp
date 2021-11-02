#include <string>
#include <iostream>
#include <vector>

using namespace std;
int dp[1001][1001][2];
string str1, str2;
vector<char> v;
int main()
{
    cin >> str1;
    cin >> str2;
    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {

            if (dp[i][j][0] < dp[i - 1][j][0])
            {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = 1;
            }
            if (dp[i][j][0] < dp[i][j - 1][0])
            {
                dp[i][j][0] = dp[i][j - 1][0];
                dp[i][j][1] = 2;
            }
            if (str1[i - 1] == str2[j - 1] && dp[i][j][0] < dp[i - 1][j - 1][0] + 1)
            {
                dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
                dp[i][j][1] = 3;
            }
        }
    }

    int i = str1.length(), j = str2.length();
    cout << dp[i][j][0] << "\n";
    while (1)
    {
        if (dp[i][j][1] == 0)
            break;
        if (dp[i][j][1] == 1)
            i--;
        else if (dp[i][j][1] == 2)
            j--;
        else if (dp[i][j][1] == 3)
        {
            i--, j--;
            v.push_back(str1[i]);
        }
    }

    while (!v.empty())
    {
        cout << v.back();
        v.pop_back();
    }
    return 0;
}