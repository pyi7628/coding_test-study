#include <cstdio>
#include <vector>
using namespace std;
int h, w, s = 0, e = 0, sum = 0;
int arr[501];
vector<int> v;
int main()
{
    scanf("%d%d", &h, &w);
    scanf("%d", &arr[0]);
    s = arr[0];
    for (int i = 1; i < w; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i - 1] <= arr[i])
        {
            s = arr[i];
        }
        else if (s > arr[i])
        {
        }
    }
    return 0;
}