#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
int n, cur_num = 0, answer = 0;
bool check[1001];
string str;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        m[str] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (m[str] != cur_num)
            answer++, check[m[str]] = true;
        else
            while (cur_num < n - 1 && check[++cur_num])
                ;
    }
    cout << answer;
    return 0;
}