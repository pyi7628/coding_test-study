#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	int input[1001] = { 0, };
	int dp_increase[1001] = { 0, };
	int dp_decrease[1001] = { 0, };
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
				max_num = max(max_num, dp_increase[j]);
			}
		}
		dp_increase[i] = max_num + 1;
		//answer = max(answer, dp_increase[i]);
	}
	for (int i = N-1; i >= 0; i--)
	{
		int max_num = 0;
		for (int j = N-1; j > i; j--)
		{
			if (input[i] > input[j])
			{
				max_num = max(max_num, dp_decrease[j]);
			}
		}
		dp_decrease[i] = max_num + 1;
		answer = max(answer, dp_increase[i] + dp_decrease[i]);
	}
	printf("%d", answer-1);
	return 0;
}