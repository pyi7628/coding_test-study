#include <string>
#include <vector>
#include <iostream>
using namespace std;

string ap = "AEIOU";
int cnt = 0;
int answer = 0;
void back_tracking(string str, string word)
{
    cnt++;
    cout << str << '\n';
    if (word.compare(str) == 0)
    {
        answer = cnt;
        return;
    }
    if (str.length() >= 5)
        return;
    for (int i = 0; i < 5; i++)
        back_tracking(str + ap[i], word);
}
int solution(string word)
{
    back_tracking("", word);
    return answer;
}
int main()
{
    solution("AAAAE");
    return 0;
}