#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int checkmin = 20000;
int arr[101][101] = { 0, };
int checkarr[101][101] = { 0, };
queue<pair<int,pair<int,int>>> q;
int main()
{
	int T;
	scanf("%d %d %d", &N, &M, &T);
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	q.push(make_pair(0, make_pair(0,0)));
	while (!q.empty())
	{
		pair<int, pair<int, int>> cur = q.front();
		int cur_row = cur.second.first;
		int cur_col = cur.second.second;
		if (cur.first <= T)
		{
			if (arr[cur_row][cur_col] == 2)
			{
				checkmin = min(checkmin, cur.first + N - cur_row + M - cur_col - 2);
			}
			if (cur_row == N - 1 && cur_col == M - 1)
			{
				checkmin = min(checkmin, cur.first);
			}
			if (cur_row + 1 < N && arr[cur_row + 1][cur_col] != 1 && checkarr[cur_row + 1][cur_col] != 1)
			{
				checkarr[cur_row + 1][cur_col] = 1;
				q.push(make_pair(cur.first + 1, make_pair(cur_row + 1, cur_col)));
			}
			if (cur_col + 1 < M && arr[cur_row][cur_col + 1] != 1 && checkarr[cur_row][cur_col + 1] != 1)
			{
				checkarr[cur_row][cur_col + 1] = 1;
				q.push(make_pair(cur.first + 1, make_pair(cur_row, cur_col + 1)));
			}
			if (cur_col - 1 >= 0 && arr[cur_row][cur_col - 1] != 1 && checkarr[cur_row][cur_col - 1] != 1)
			{
				checkarr[cur_row][cur_col - 1] = 1;
				q.push(make_pair(cur.first + 1, make_pair(cur_row, cur_col - 1)));
			}
			if (cur_row - 1 >= 0 && arr[cur_row - 1][cur_col] != 1 && checkarr[cur_row - 1][cur_col] != 1)
			{
				checkarr[cur_row - 1][cur_col] = 1;
				q.push(make_pair(cur.first + 1, make_pair(cur_row - 1, cur_col)));
			}
		}
		q.pop();
	}
	if (checkmin == 20000 || checkmin > T)printf("Fail");
	else printf("%d", checkmin);
	return 0;
}

