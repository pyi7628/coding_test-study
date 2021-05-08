#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k)
{
    int minNum = INT_MAX;
    for (int i = 0; i < stones.size() - k + 1; i++)
    {
        int *maxNumAddr = max_element(&stones[i], &stones[i + k]);
        if (minNum > *maxNumAddr)
            minNum = *maxNumAddr;
        i += maxNumAddr - &stones[i];
    }
    return minNum;
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    return 0;
}