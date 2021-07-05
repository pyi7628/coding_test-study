#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << s << '\n';
    }
    return 0;
    // 5개는 꼭 알려줘야함
    // 경우의 수를 모두 구하고 , 그 경우의 수에 대해 얼마나 읽을 수 있느지 돌려보기 -> 복잡도 높지만 가능은 하다
}