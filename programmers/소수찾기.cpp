#include <string>
#include <vector>

using namespace std;

bool validation(int num);

string g_numbers;

//근데 이렇게 전역으로하면 다른 test케이스에서 초기화 되남...???ㅜㅠㅠㅜ-> 알아서 되는듯하당

//vector<int> list;
int check_exist[10000000] ={0,};//vector에 해당 값 있는지 확인
int count_num=0;



void makeNumber(string num_list, int* check){

    int num = atoi(num_list.c_str());

    if(check_exist[num] == 0) 
    {
        
        if(validation(num))
        {
            count_num++;
        
        }

        check_exist[num]=1;
    }

  
    for(int i=0; i<g_numbers.size(); i++)
    {
       
       
        if(check[i]!=1)
        {
            int temp[10]={0,};
            for(int j=0; j<g_numbers.size(); j++)
            {
                temp[j]=check[j];
            }

            temp[i] =1;
            
             
           
            string sub = num_list+g_numbers.at(i);

            makeNumber(sub, temp);

        }


    }
}


//각 num의 값이 소수인지 확인
bool validation(int num)
{
    if(num==1||num==0) return false;
    for(int i = 2; i<=num/2; i++)
    {
        if(num%i==0) return false;
    }
    return true;
    

}


int solution(string numbers) {
    int answer = 0;

    g_numbers = numbers;
    
    for(int i =0 ; i<numbers.size(); i++)
    {
        int temp[10]={0,};

        temp[i]=1;

        if(numbers.at(i)!='0') {

            string sub;
            sub= sub+numbers.at(i);
            makeNumber(sub, temp);
        }
    }

    answer = count_num;

    return answer;
}