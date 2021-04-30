#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
int main(){
	int n = 0;
	scanf("%d", &n);
	int arr[1002][4] = { 0, };
	int result[1002][4] = { 0, };
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1;i < n;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (j == 0)
			{
				arr[i][j] += MIN(arr[i - 1][1], arr[i - 1][2]);
			}
			else if (j == 1)
			{
				arr[i][j] += MIN(arr[i - 1][0], arr[i - 1][2]);
			}
			else arr[i][j] += MIN(arr[i - 1][0], arr[i - 1][1]);
		}
	}
	int min = MIN(arr[n-1][1], arr[n - 1][2]);
	min = MIN(min, arr[n - 1][0]);
	printf("%d\n", min);
	
	return 0;
}