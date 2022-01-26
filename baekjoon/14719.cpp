#include <cstdio>
#include <algorithm>
using namespace std;
int arr[501];
int h, w, left = 0, right = 0, sum = 0;
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 0; i < w; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i < w - 1; i++)
    {
        left = 0, right = 0;
        for (int j = 0; j < i; j++)
        {
            if (left < arr[j])
                left = arr[j];
        }
        for (int j = i + 1; j < w; j++)
        {
            if (right < arr[j])
                right = arr[j];
        }
        if (left > arr[i] && right > arr[i])
            sum += (min(left, right) - arr[i]);
    }
    printf("%d", sum);
    return 0;
}