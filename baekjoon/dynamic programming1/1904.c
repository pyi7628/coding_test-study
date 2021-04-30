#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001] = {0,};

int main()
{
	int N = 0;
	scanf("%d", &N);
	
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N+1; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2])% 15746;
	}
	printf("%d", arr[N+1]);
	
	return 0;
}