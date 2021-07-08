#include <cstdio>
#include <vector>
using namespace std;
bool che[3200]; // sqrt(10,000,000) , 체크 없으면 소수
vector<int> prime;
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
        return 0;
    // 소수 구하기, 에라토스테네스 체
    for (int i = 2; i < 3200; i++)
    {
        if (che[i])
            continue;
        for (int j = i + i; j < 3200; j += i)
        {
            che[j] = true;
        }
        for (int i = 2; i < 3200; i++)
        {
            if (che[i] == false)
                prime.push_back(i);
        }
    }
    for (int i = 0; i < prime.size(); i++)
    {
        while (n % prime[i] == 0)
        {
            printf("%d\n", prime[i]);
            n /= prime[i];
        }
    }
    if (n > 1) //나눠진 애가 안나왔따!!!!
    {
        printf("%d\n", n);
    }
    return 0;
}