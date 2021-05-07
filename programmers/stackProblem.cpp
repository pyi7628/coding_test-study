#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string inputString)
{
    int answer = 0;
    stack<pair<char, char> > s;
    int i = 0;
    int cnt = 0;
    for (i = 0; i < inputString.length(); i++)
    {

        if (inputString[i] == '(')
        {
            s.push(make_pair('(', ')'));
        }
        else if (inputString[i] == '{')
        {
            s.push(make_pair('{', '}'));
        }
        else if (inputString[i] == '[')
        {
            s.push(make_pair('[', ']'));
        }
        else if (inputString[i] == '<')
        {
            s.push(make_pair('<', '>'));
        }
        else if (inputString[i] == ')' || inputString[i] == '}' || inputString[i] == ']' || inputString[i] == '>')
        {
            if (s.empty())
            {
                answer = -i;
                printf("em: %d %c \n", answer, inputString[i]);
                break;
            }
            else if (s.top().second != inputString[i])
            {
                answer = -i;
                printf("an: %d %c %c\n", answer, s.top().first, inputString[i]);
                s.pop();
                break;
            }
            else if (s.top().second == inputString[i])
            {
                s.pop();
                cnt++;
            }
        }
    }
    if (s.empty() && answer == 0)
        answer = cnt;
    else if (!s.empty() && answer == 0)
        answer = -i + 1;

    printf("%d\n", answer);
    return answer;
}

int main()
{

    solution("Hello, world!");
    return 0;
}