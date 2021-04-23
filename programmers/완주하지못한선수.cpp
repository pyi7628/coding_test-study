#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> hmap;

    for(string name: participant){
        hmap[name]++;
    }
    for(string name: completion){
        hmap[name]--;
    }
    for(auto p: hmap){
        if(p.second>0){
            return p.first;
        }
    }
  
}