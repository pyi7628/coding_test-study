#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
vector<pair<char, int> > v;

bool sorting(pair<char, int> &a, pair<char, int> &b)
{
    return a.first < b.first;
}

void recur(int point, int cnt, int mo, int ja, vector<char> str)
{

    pair<char, int> p;
    p = v[point];
    if (p.second == 1)
        mo++;
    else
        ja++;
    str.push_back(p.first);
    cnt++;
    if (cnt == l)
    {
        if (mo >= 1 && ja >= 2)
        {
            for (int i = 0; i < l; i++)
            {
                printf("%c", str[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = point + 1; i < v.size(); i++)
    {
        recur(i, cnt, mo, ja, str);
    }
}
int main()
{

    scanf("%d%d", &l, &c);
    getchar();
    for (int i = 0; i < c; i++)
    {
        char letter;
        int type = 0;

        scanf(" %c", &letter);
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            type = 1;
        v.push_back(make_pair(letter, type));
    }

    sort(v.begin(), v.end(), sorting);
    int ja = 0;
    int mo = 0;

    vector<char> str;

    for (int i = 0; i <= v.size() - l; i++)
    {
        recur(i, 0, 0, 0, str);
    }
    return 0;
}