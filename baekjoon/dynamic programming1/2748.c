#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long arr[91] = {0,};

int main()
{
	int N = 0;
	scanf("%d", &N);
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%lld", arr[N]);
	
	return 0;
}