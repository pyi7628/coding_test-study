#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int row, col = 0;
    int S = brown + yellow;

    int mid = sqrt(S);

    while(S%mid!=0)
    {
        mid++;
    }

    int expected_col = 0;

    for(int i = mid; i<=S; i++){
        if(S%i==0){
            
            expected_col = S/i;

            int expected_brown = (expected_col + i)*2 - 4;
            if(expected_brown==brown)
            {
                answer.push_back(i);
                answer.push_back(expected_col);

                break;
            }
            
        }
    }

    return answer;
}