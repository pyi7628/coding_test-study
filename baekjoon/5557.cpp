#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct 
{
	int value;
	long long arr[21];
}DP;
DP dp[101];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &dp[i].value);
		for (int j = 0; j < 21; j++)
		{
			dp[i].arr[j] = 0;
		}
	}
	dp[0].arr[dp[0].value] = 1;//init
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (dp[i - 1].arr[j] > 0)
			{
				if (j + dp[i].value <= 20) dp[i].arr[j + dp[i].value] += dp[i - 1].arr[j];
				if (j - dp[i].value >= 0) dp[i].arr[j - dp[i].value] += dp[i - 1].arr[j];
			}
		}
	}
	printf("%lld", dp[N - 2].arr[dp[N - 1].value]);
	return 0;
}