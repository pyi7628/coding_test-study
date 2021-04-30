#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	scanf("%d", &N);

	int** input = (int**)malloc(sizeof(int*) * (N + 1));//2차원 DP
	for (int i = 0; i < N; i++)
	{
		input[i] = (int*)malloc(sizeof(int) * (i + 2));
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}
	
	int max = -1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) input[i][j] += input[i - 1][0]; 
			else if (j == i) input[i][j] += input[i - 1][i - 1];
			else input[i][j] += MAX(input[i - 1][j - 1], input[i - 1][j]);
			if (i == N - 1)
			{
				if (max < input[i][j]) max = input[i][j];
			}
		}
	}

	printf("%d", max);
	
	return 0;
}

/*if (i + 1 == N)
		{
			dp_arr[i] = MAX(input[i][cur], input[i][cur + 1]) + dp_arr[i - 1];
			break;
		}
		if (input[i][cur] + MAX(input[i + 1][cur], input[i + 1][cur + 1]) <
			input[i][cur + 1] + MAX(input[i + 1][cur + 1], input[i + 1][cur + 2]))
		{
			cur = cur + 1;
		}
		dp_arr[i] = input[i][cur] + dp_arr[i - 1];
		*///처음에 타고 내려올 수 있다고 생각하여 dp for문을 이렇게 짰었음. 놓치는 부분이 생겨서 2차원으로 수정함.
