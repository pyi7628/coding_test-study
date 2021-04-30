#define _CRT_SECURE_NO_WARNINGS
#define CHECK(a, b) ((a % b == 0) ? (a / b) : (0))
#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1000002] = { 0, };
int main()
{	
	int N = 0;
	scanf("%d", &N);
	dp[0] = 1000001;
	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = min({ dp[i - 1], dp[CHECK(i, 2)], dp[CHECK(i, 3)] }) + 1;
	}
	printf("%d", dp[N]);
	return 0;
}