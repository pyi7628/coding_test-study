#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// struct Node
// {
//     int num;
//     Node *next;
// };

// Node *list;
// void init(int n)
// {
//     for (int i = n - 1; i >= 0; i++)
//     {
//         Node *node = (Node *)malloc(sizeof(Node));
//         node->num = i;
//         node->next = NULL;

//         if (list == NULL)
//         {
//             list = node;
//         }
//         else
//         {
//             node->next = list;
//             list = node;
//         }
//     }
// }
// void add(int num, int i)
// {
//     Node *node = (Node *)malloc(sizeof(Node));
//     node->num = i;
//     node->next = NULL;

//     if (list == NULL)
//     {
//         list = node;
//     }
//     else
//     {
//         Node *prev = list;
//         Node *cur = list;
//         while (cur->next != NULL)
//         {
//             //if (cur->next->num == i - 1)
//         }

//         list = node;
//     }
// }
string solution(int n, int k, vector<string> cmd)
{
    //stack<Node> s;
    stack<pair<int, int> > s; // cur 위치, real idx
    vector<int> v;
    int curTotal = n;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    string answer = "";
    int cur = k;

    for (int i = 0; i < cmd.size(); i++)
    {

        if (cmd[i][0] == 'U')
        {
            string sub = cmd[i].substr(cmd[i].length() - 2);
            cur -= stoi(sub);
        }
        else if (cmd[i][0] == 'D')
        {
            string sub = cmd[i].substr(cmd[i].length() - 2);
            cur += stoi(sub);
        }
        else if (cmd[i][0] == 'C')
        {
            s.push(make_pair(cur, v[cur]));
            //v.erase(v.begin() + cur);
            curTotal -= 1;
            if (curTotal == cur)
                cur -= 1;
        }
        else if (cmd[i][0] == 'Z')
        {
            pair<int, int> curTop = s.top();
            s.pop();
            curTotal += 1;
            //v.insert(v.begin() + curTop.first, curTop.second);
            if (cur >= curTop.first)
                cur += 1;
        }
        printf("cur: %d\n", cur);
    }
    int cnt = 0;
    for (int i = 0; i < v.size();)
    {
        if (v[i] != cnt)
            answer.append("X");
        else
        {
            answer.append("O");
            i++;
        }

        cnt++;
    }
    return answer;
}

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    //stack<Node> s;
    stack<pair<int, int> > s; // cur 위치, real idx
    vector<int> v;
    int curTotal = n;
    int count[1000002] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    string answer = "";
    int cur = k;

    for (int i = 0; i < cmd.size(); i++)
    {

        if (cmd[i][0] == 'U')
        {
            string sub = cmd[i].substr(cmd[i].length() - 2);
            cur -= stoi(sub);
        }
        else if (cmd[i][0] == 'D')
        {
            string sub = cmd[i].substr(cmd[i].length() - 2);
            cur += stoi(sub);
        }
        else if (cmd[i][0] == 'C')
        {
            stack<pair<int, int> > temp = s;
            int num = 0;
            while (!temp.empty())
            {
                pair<int, int> t = s.top();
                temp.pop();
                if (cur >= t.first)
                    num++;
            }
            s.push(make_pair(cur, v[cur] + num));
            //v.erase(v.begin() + cur);
            curTotal -= 1;
            if (curTotal == cur)
                cur -= 1;
        }
        else if (cmd[i][0] == 'Z')
        {
            pair<int, int> curTop = s.top();
            s.pop();
            curTotal += 1;
            //v.insert(v.begin() + curTop.first, curTop.second);
            if (cur >= curTop.first)
                cur += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        answer.append("O");
    }
    while (!s.empty())
    {
        pair<int, int> curTop = s.top();
        s.pop();
        answer[curTop.second] = 'X';
    }

    return answer;
}