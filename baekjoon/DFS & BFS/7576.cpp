#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int r;
	int c;
}POINT_ONE;
int arr[1024][1024];
POINT_ONE point_one[1000002];
int main()
{
	int M;
	int N;
	scanf("%d %d", &M, &N);
	int cnt_zero = 0;
	int cnt_one = 0;
	int cnt_day = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				cnt_zero++;
			}
			if (arr[i][j] == 1)
			{
				point_one[cnt_one].r = i;
				point_one[cnt_one++].c = j;
			}
		}

	}
	if (cnt_zero == 0)
	{
		printf("0\n");
		return 0;
	}
	if (cnt_one == 0)
	{
		printf("-1\n");
		return 0;
	}
int done = 0;
int temp_one = cnt_one;
int pre_zero = cnt_zero;
while (done<cnt_one)
{
	if (cnt_zero <= 0) break;
	for (int i = 0;i<temp_one;i++)
	{
		int cur_r = point_one[done].r;
		int cur_c = point_one[done++].c;
		if (cur_r - 1 >= 0 && arr[cur_r - 1][cur_c] == 0)
		{
			arr[cur_r - 1][cur_c] = 1;
			cnt_zero--;
			point_one[cnt_one].r = cur_r - 1;
			point_one[cnt_one++].c = cur_c;

		}
		if (cur_r + 1 < N && arr[cur_r + 1][cur_c] == 0)
		{
			arr[cur_r + 1][cur_c] = 1;
			cnt_zero--;
			point_one[cnt_one].r = cur_r + 1;
			point_one[cnt_one++].c = cur_c;
		}
		if (cur_c - 1 >= 0 && arr[cur_r][cur_c - 1] == 0)
		{
			arr[cur_r][cur_c - 1] = 1;
			cnt_zero--;
			point_one[cnt_one].r = cur_r;
			point_one[cnt_one++].c = cur_c - 1;
		}
		if (cur_c + 1 < M && arr[cur_r][cur_c + 1] == 0)
		{
			arr[cur_r][cur_c + 1] = 1;
			cnt_zero--;
			point_one[cnt_one].r = cur_r;
			point_one[cnt_one++].c = cur_c + 1;
		}
	}
	temp_one = cnt_one - done;
	cnt_day++;
	if (cnt_zero == pre_zero)
	{
		printf("-1\n");
		return 0;
	}
	pre_zero = cnt_zero;
}                                                                                    printf("%d\n", cnt_day);
return 0;

}