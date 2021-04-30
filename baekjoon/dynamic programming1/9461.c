#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long arr[102] = {0,};

int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T)
	{
		int N = 0;
		scanf("%d", &N);
		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 1;
		arr[4] = 2;
		arr[5] = 2;
		arr[6] = 3;
		arr[7] = 4;
		arr[8] = 5;
		arr[9] = 7;
		arr[10] = 9;
		for (int i = 11; i <= N; i++)
		{
			arr[i] = arr[i - 5] + arr[i - 1];
		}
		printf("%lld\n", arr[N]);
		T--;
	}
	return 0;
}