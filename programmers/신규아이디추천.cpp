#include <string>
#include <vector>
#include <iostream>

using namespace std;

// check UpperCase
string first(string id)
{
    string result = id;
    for (int i = 0; i < id.length(); i++)
    {
        result[i] = tolower(id[i]);
    }
    return result;
}
string second(string id)
{
    string result = "";
    for (int i = 0; i < id.length(); i++)
    {
        result[i] = tolower(id[i]);
    }
    return result;
}
string third(string id)
{
}
string fourth(string id)
{
}
string fifth(string id)
{
}
string sixth(string id)
{
}
string seventh(string id)
{
}
string solution(string new_id)
{
    string answer = "";
    answer = first(new_id);

    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << solution(str) << "\n";
    return 0;
}