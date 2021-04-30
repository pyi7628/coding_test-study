#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long arr[41][2] = {0,};

int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T)
	{
		int N = 0;
		scanf("%d", &N);

		arr[0][0] = 1;
		arr[0][1] = 0;
		arr[1][0] = 0;
		arr[1][1] = 1;
		for (int i = 2; i <= N; i++)
		{
			arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
			arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
		}
		printf("%lld %lld\n", arr[N][0], arr[N][1]);
		T--;
	}
	
	
	return 0;
}