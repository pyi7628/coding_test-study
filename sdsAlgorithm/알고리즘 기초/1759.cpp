#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int l, c;
    vector<char> v;
    scanf("%d%d", &l, &c);
    getchar();
    for (int i = 0; i < c; i++)
    {
        char letter;

        scanf(" %c", &letter);

        v.push_back(letter);
    }
    for (int i = 0; i < v.size(); i++)
    {
        printf("%c", v[i]);
    }
    return 0;
}