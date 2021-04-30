#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*(n + 2));
	int *sum = (int*)malloc(sizeof(int)*(n + 2));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum[i] = 0;
	}
	int max = arr[0];
	sum[0] = arr[0];
	for (int i = 1;i < n;i++)
	{
		if (sum[i - 1] + arr[i] > 0 && sum[i - 1] > 0)
		{
			sum[i] = sum[i - 1] + arr[i];
		}
		else sum[i]=arr[i];
		if (max < sum[i])
		{
			max = sum[i];
		}
	}
	printf("%d\n", max);

    return 0;
}