#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[102][10] = { 0, };
int main()
{
	int N;
	scanf("%d", &N);

	for (int j = 1; j < 10; j++)
	{
		dp[1][j] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		
	}
	long long sum = 0;
	for (int j = 0; j < 10; j++)
	{
		sum = (dp[N][j]+sum) % 1000000000;
	}

	printf("%lld", sum);
	return 0;
}
