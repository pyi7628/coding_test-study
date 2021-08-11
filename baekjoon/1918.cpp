#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
struct OP
{
    char op;
    int priority;
};
struct OPD
{
    char opd;
    int priority;
};
int priority = 0;
string str;
vector<OP> opv;
vector<OPD> opdv;

bool isOp(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int get_priority(char c)
{
    if (c == '+')
        return 1;
    else if (c == '-')
        return 1;
    else if (c == '*')
        return 2;
    else if (c == '/')
        return 2;
}
bool check_priority(char c)
{
    return priority > opv.back().priority || (priority == opv.back().priority && get_priority(c) > get_priority(opv.back().op));
}
void check_printing(char c)
{
    for (int j = 0; j < opdv.size(); j++)
    {
        printf("%c", opdv[j].opd);
    }
    opdv.clear();
    OP temp = opv.back();
    while (!opv.empty() && (temp.priority > priority || temp.priority == priority && get_priority(c) <= get_priority(temp.op)))
    {
        printf("%c", opv.back().op);
        opv.pop_back();
        temp = opv.back();
    }
}
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (isOp(str[i]))
        {
            OP temp;
            temp.op = str[i];
            temp.priority = priority;
            if (!opv.empty() && !check_priority(str[i]))
            {
                check_printing(str[i]);
            }
            opv.push_back(temp);
        }
        else if (str[i] == '(')
            priority++;
        else if (str[i] == ')')
            priority--;
        else
        {
            OPD temp;
            temp.opd = str[i];
            temp.priority = priority;
            opdv.push_back(temp);
        }
    }
    check_printing('+');
    return 0;
}