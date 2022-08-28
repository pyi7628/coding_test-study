#include <string>
#include <vector>

using namespace std;

int max_score = 0;
vector<int> result;
vector<int> v;
void dfs(int n, int cnt, vector<int> info)
{
    int idx = v.size();

    if (idx >= 11)
    {
        int a_score = 0, l_score = 0;
        v[10] += n - cnt; //남은거 있으면 마지막에 더해주기

        for (int i = 0; i < 11; i++)
        {
            if (info[i] < v[i])
            {
                l_score += 10 - i;
            }
            else if (info[i] != 0)
                a_score += 10 - i;
        }

        if (max_score < l_score - a_score)
        {
            max_score = l_score - a_score;
            result.clear();
            for (int i = 0; i < 11; i++)
            {
                result.push_back(v[i]);
            }
        }
        else if (max_score == l_score - a_score)
        {
            for (int i = 10; i >= 0; i--)
            {
                if (result.size() > 0 && result[i] < v[i])
                {
                    result.clear();
                    for (int j = 0; j < 11; j++)
                    {
                        result.push_back(v[j]);
                    }
                    break;
                }
                else if (result.size() > 0 && result[i] > v[i])
                {
                    break;
                }
            }
        }
        return;
    }
    else
    {

        if (info[idx] < n - cnt)
        {
            v.push_back(info[idx] + 1);
            dfs(n, cnt + info[idx] + 1, info);
            v.pop_back();
        }
        v.push_back(0);
        dfs(n, cnt, info);
        v.pop_back();
    }
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    dfs(n, 0, info);

    if (result.size() == 0)
        result.push_back(-1);
    return result;
}
