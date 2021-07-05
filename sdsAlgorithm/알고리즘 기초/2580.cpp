#include <cstdio>
#include <stdlib.h>

using namespace std;

bool pruning(int r, int c, int num, int arr[10][10])
{
    //작은 사각형
    int mr = r / 3;
    mr *= 3;
    int mc = c / 3;
    mc *= 3;
    printf("prun num: %d r: %d c: %d \n", num, r, c);
    for (int i = mr; i < mr + 3; i++)
    {
        for (int j = mc; j < mc + 3; j++)
        {
            if (arr[i][j] == num)
            {
                printf("test1 fail num: %d i: %d j: %d\n", num, i, j);
                return false;
            }
        }
    }
    printf("test1\n");
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][c] == num)
            return false;
    }
    printf("test2\n");
    for (int i = 0; i < 9; i++)
    {
        if (arr[r][i] == num)
            return false;
    }
    printf("test3\n");
    return true;
}
void back(int r, int c, int arr[10][10])
{
    printf("back r: %d c: %d\n", r, c);
    if (r == -1 || c == -1)
    {
        printf("answer\n");
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    int next_r = -1, next_c = -1;
    int temp[10][10] = {
        0,
    };
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            temp[i][j] = arr[i][j];
            if (!(i == r && j == c) && next_c == -1 && next_r == -1 && arr[i][j] == 0)
            {
                printf("next i: %d j: %d\n", i, j);
                next_r = i;
                next_c = j;
            }
        }
    }

    for (int k = 1; k <= 9; k++)
    {
        printf("!!!! r: %d, c: %d, num: %d %d\n", next_r, next_c, k, arr[r][c]);
        if (arr[r][c] == 0 && pruning(r, c, k, arr))
        {
            temp[r][c] = k;
            // printf("!!!! r: %d, c: %d, num: %d\n", next_r, next_c, k);
            back(next_r, next_c, temp);
        }
    }
}

int main()
{
    int arr[10][10] = {
        0,
    };
    int next_r = -1, next_c = -1;

    // if(next_c==-1|| next_r==-1)
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (next_c == -1 && next_r == -1 && arr[i][j] == 0)
            {
                printf("fisrt next i: %d j: %d\n", i, j);
                next_r = i;
                next_c = j;
            }
        }
    }

    back(next_r, next_c, arr);
    return 0;
}