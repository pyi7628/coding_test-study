#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int input[301] = { 0, };
	int dp[301] = { 0, };
	int N = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
	}
	dp[0] = input[0];
	dp[1] = input[0] + input[1];
	dp[2] = max(input[0] + input[2], input[1] + input[2]);
	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i - 2] + input[i], input[i - 1] + dp[i - 3] + input[i]);
	}

	printf("%d", dp[N - 1]);

	return 0;
}
