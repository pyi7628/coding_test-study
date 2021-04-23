#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> hmap;

    for(vector<string> c: clothes){
        hmap[c[1]]++;
    }

    for(int i =0; i<hmap.size();i++){
        
    }
    return answer;
}