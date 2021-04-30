#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int checkmin = 20000;
int arr[26][26] = { 0, };
int checkarr[26][26] = { 0, };
int countarr[650] = { 0 };

queue<pair<int, int>> q;
int main()
{
	
	scanf("%d", &N);
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	int num = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] && !checkarr[i][j])
			{
				checkarr[i][j] = 1;
				q.push(make_pair(i, j));
				countarr[num]++;

				while (!q.empty())
				{

					int cur_row = q.front().first;
					int cur_col = q.front().second;
					

					if (cur_row + 1 < N && arr[cur_row + 1][cur_col] != 0 && checkarr[cur_row + 1][cur_col] != 1)
					{
						checkarr[cur_row + 1][cur_col] = 1;
						q.push(make_pair(cur_row + 1, cur_col));
						countarr[num]++;
					}
					if (cur_col + 1 < N && arr[cur_row][cur_col + 1] != 0 && checkarr[cur_row][cur_col + 1] != 1)
					{
						checkarr[cur_row][cur_col + 1] = 1;
						q.push(make_pair(cur_row, cur_col + 1));
						countarr[num]++;
					}
					if (cur_col - 1 >= 0 && arr[cur_row][cur_col - 1] != 0 && checkarr[cur_row][cur_col - 1] != 1)
					{
						checkarr[cur_row][cur_col - 1] = 1;
						q.push(make_pair(cur_row, cur_col - 1));
						countarr[num]++;
					}
					if (cur_row - 1 >= 0 && arr[cur_row - 1][cur_col] != 0 && checkarr[cur_row - 1][cur_col] != 1)
					{
						checkarr[cur_row - 1][cur_col] = 1;
						q.push(make_pair(cur_row - 1, cur_col));
						countarr[num]++;
					}

					q.pop();
					if (q.empty()) num++;
				}
			}
			
		}
	}
	sort(countarr + 1, countarr + num);
	printf("%d\n", num - 1);
	for (int i = 1; i < num; i++)
	{
		printf("%d\n", countarr[i]);
	}
	
	return 0;
}