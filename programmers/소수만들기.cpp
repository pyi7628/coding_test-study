#include <vector>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int cnt = 0;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void recul(vector<int> nums, int sum, int depth, int last)
{
    if (depth >= 3 && isPrime(sum))
    {
        cnt++;
        return;
    }
    if (last > nums.size() - 4)
    {
        return;
    }
    for (int i = last + 1; i < nums.size(); i++)
    {
        recul(nums, sum + nums[i], depth + 1, i);
    }
}
int solution(vector<int> nums)
{
    int answer = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        recul(nums, nums[i], 1, i);
    }
    cout << "Hello Cpp" << endl;

    answer = cnt;
    return answer;
}

int main()
{
}