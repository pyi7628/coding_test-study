// low bound, upper bound
// or
//

// A,B / C,D로 반을 쪼개는 것이 포인트! => 그리고 나눈 것 끼리 (ex: A,B) 각각 섞는다(조합한다).
// 각각 섞으면 16000000개(4000*4000)의 경우의 수가 나오는데 너무 큰거 아닌가..?
// 그리고 결국 A,B / C,D 각각 조합한 거를 다시 조합하면 또 16000000개(4000*4000) * 16000000개(4000*4000) 라서 결국 똑같다...
// A,B 조합이 3이라면 C,D 조합에서 -3인 애를 세는 방식.. A,B 조합에서 이미 한번 셌던 숫자인 애들은 다시 재사용도 가능
// 정렬을 해서 찾으면 더 좋지 않을까!? => 16000000 (nlog n)이면 16000000*24 => 1억정도인데 1초 수행시간이니 가능할 듯!?
// => 하지만 그 값이 있는 구간을 어떻게 효율적으로 찾지?, 이분 탐색도 불가능!
// map을 써도 좋지 않을까!?!? => 해쉬맵, 트리맵 (log n) 인데 결국 n 번 탐색해야하니 (nlog n)이다. 이거도 괜찮다!

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

vector<int> a, b, c, d;
vector<int> ab, cd;
LL answer;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int n1, n2, n3, n4;
        scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
        a.push_back(n1);
        b.push_back(n2);
        c.push_back(n3);
        d.push_back(n4);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //   printf("c: %d d: %d\n", c[i], d[j]);
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    // 전략 1. 정렬없이 map 사용
    // 전략 2. 정렬
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    // 전략 2-1. low, upper bound => compare에서 최초로 false가 되는 지점으로 판단
    // 전략 2-2. 안쓰고 => ad는 start 부터, cd는 end부터 하나씩 보면서 조합 합이 0되는거 세어주기, 근데 2개 연달아 나오는거 잘 처리하기!
    int ptr_e = cd.size() - 1;
    LL cnt = 0;
    for (int ptr_s = 0; ptr_s < ab.size(); ptr_s++)
    {
        int target = ab[ptr_s] * (-1);
        if (ptr_s > 0 && ab[ptr_s] == ab[ptr_s - 1])
        {
            answer += cnt;
        }
        else
        {
            cnt = 0;
            // printf("test:  target: %d , cd: %d, ptr: %d\n", target, c[ptr_e], ptr_e);
            while (0 <= ptr_e && target < cd[ptr_e])
            {
                ptr_e--;
            }
            while (0 <= ptr_e && target == cd[ptr_e])
            {

                cnt++;
                ptr_e--;
            }
            // printf("+cnt: %lld\n", cnt);
            answer += cnt;
        }
    }
    printf("%lld", answer);

    return 0;
}