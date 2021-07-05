#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int left = 0;
        int right = N - 1;
        int num;
        scanf("%d", &num);
        while (1)
        {
            int center = (left + right) / 2;
            if (left > right)
            {
                printf("0\n");
                break;
            }
            if (v[center] == num)
            {
                printf("1\n");
                break;
            }
            if (v[center] < num)
            {
                left = center + 1;
            }
            else
            {
                right = center - 1;
            }
        }
    }
    return 0;
}