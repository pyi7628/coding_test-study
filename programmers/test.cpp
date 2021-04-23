#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){

    int N, cur_d, min_d=0;
    vector<int> v;
    vector<int> answer;
    scanf("%d", &N);

    int max_num=2*N-1;

    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d", &num);

        v.push_back(num);
    }

    sort(v.begin(), v.end(), greater<int>());

    answer[0]=v[0];
    answer[1]=v[1];
    answer[2]=v[2];
    for(int i=3;i<N;i++)
    {
        if(answer[0]>answer[1]||answer[0]>answer[2]){
            if(answer[1]>answer[2])
            {
                answer[2]+=v[i];
            }
            else
            {
                answer[1]+=v[i];
    
            }
            
        }
        else
        {
            answer[0]+=v[i];
        }
        
        
    }
    sort(answer.begin(), answer.end(), greater<int>());

    for(int i=0;i<3;i++){
        printf("%d ", answer[i]);
    }

}