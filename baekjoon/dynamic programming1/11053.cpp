#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	int input[1001] = { 0, };
	int dp[1001] = { 0, };
	scanf("%d", &N);
	int answer = 1;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
		int max_num = 0;
		for (int j = 0; j < i; j++)
		{
			if (input[i] > input[j])
			{
				max_num = max(max_num, dp[j]);
			}
		}
		dp[i] = max_num + 1;
		answer = max(answer, dp[i]);
	}
	printf("%d", answer);
	return 0;
}