#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];
string str1, str2;
int answer = 0;
int main()
{
    cin >> str1;
    cin >> str2;

    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            if (dp[i][j] > answer)
                answer = dp[i][j];
        }
    }
    cout << answer;
    return 0;
}