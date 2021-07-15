//index 트리
// #include <cstdio>
// int main()
// {
// }

#include <cstdio>
#include <iostream>
using namespace std;
#define PIV (1 << 4)      // 1~16 N 10만
int leafnode = (1 << 17); // N이 10만
long long tree[PIV * 2];
void update(int n, int v)
{
    n += PIV;
    tree[n] = v;
    n /= 2; // 바로위 부모에서 시작
    while (n > 0)
    {
        // 조상 = 왼쪽자식 + 오른쪽자식
        // 구간합의 최대를 구하고 싶으면 root를 Max(왼쪽, 오른쪽)으로 저장한다!=>결합법칙이 성립하는 경우에 대해 모두 가능
        // ex) 덧셈, 최대, 최소, gcd, 곱셈, xor 등등 결합법칙이 성립하는 애들에 대하여 적용가능...!
        // 이전 강사님이 말했던게 이거다...!!!!
        // 가장 긴 증가하는 부분 수열 dp문제도 index tree로 풀수 있음!!(LIS)
        tree[n] = tree[n * 2] + tree[n * 2 + 1];
        n /= 2; // 그 윗 조상으로 옮김
    }
}
long long query(int l, int r) // 2~7 까지의 구간합
{
    l += PIV, r += PIV;
    long long ret = 0;
    while (l <= r)
    {
        if (l % 2 == 1)
            // ret = max(ret, tree[l++]);
            ret += tree[l++];
        if (r % 2 == 0)
            // ret = max(ret, tree[r--]);
            ret += tree[r--];
        l /= 2, r /= 2;
    }
    return ret;
}

//0,1,2... 라는 순서를 가지는 배열이 있을때
/// 3번째 값을 6으로 바꿔라
int main()
{
    long long ret = query(3, 8); // 33
    update(2, 6);
    ret = query(3, 8); // 36
}
