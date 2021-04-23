#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    int cal=prices.size();

    vector<int> answer(cal);

    stack<int> s;


    for(int i=0;i<cal;i++){
       
        while(!s.empty() && prices[s.top()]>prices[i]){
            answer[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }

   

    while(!s.empty())
    {
        answer[s.top()]=cal-s.top()-1;
        s.pop();
       
    }


    return answer;
}