#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int check[102] = { 0, };
	int M;
	scanf("%d", &M);
	int cnt = 0;
	int** arr = (int**)malloc(sizeof(int*) * (M + 1));
	queue<int> q;
	q.push(1);
	check[1] = 1;
	for (int i = 0; i < M; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * 3);
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < M; i++)
		{
			if (cur == arr[i][0] && check[arr[i][1]] == 0)
			{
				q.push(arr[i][1]);
				check[arr[i][1]] = 1;
			}
			if (cur == arr[i][1] && check[arr[i][0]] == 0)
			{
				q.push(arr[i][0]);
				check[arr[i][0]] = 1;
			}
		}
	}
	printf("%d", cnt - 1);
	return 0;
}

