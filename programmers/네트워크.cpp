#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int> > computers)
{
    int answer = 0;
    vector<int> checkArr(n, 0);
    queue<int> q;
    checkArr[0] = 1;
    q.push(0);
    while (!q.empty())
    {
        int curNum = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (i != curNum && checkArr[i] == 0 && computers[curNum][i] == 1)
            {
                checkArr[i] = 1;
                q.push(i);
            }
        }
        if (q.empty())
        {
            answer++;
            for (int i = 0; i < n; i++)
            {
                if (checkArr[i] == 0)
                {
                    checkArr[i] = 1;
                    q.push(i);
                    break;
                }
            }
        }
    }

    return answer;
}