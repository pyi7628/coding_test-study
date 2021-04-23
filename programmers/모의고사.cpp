#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    

   /* int count[4] = {0,};

 

    int c1 = 1;// s1's answer , compare with answers
    int c2 = 1;
    int c3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int c3_counter = 0;
    
    int max_num = 0;
    
    for(int i =0; i < answers.size(); i++){

        if(c1==6) c1=1;
        if(c2==6) c2=1;
        if(c3_counter==10) c3_counter=0;

        //S1
        if(c1==answers[i]) count[0]++;
        c1++;
        
        //S2
        if(i%2==0){
            if(2==answers[i]) count[1]++;
        }
        else{
            if(c2==answers[i]) count[1]++;
            c2++;
        }

        //S3
        if(c3[c3_counter]==answers[i]) count[2]++;
        c3_counter++;
        

    }

    for(int i =0; i<3; i++)
    {
        if(max_num<count[i]) max_num = count[i];
    }
    for(int i =0; i<3; i++)
    {
        if(max_num==count[i]) answer.push_back(i);
    }
    */
    return answer;
}