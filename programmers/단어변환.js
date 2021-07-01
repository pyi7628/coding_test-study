const isPossible = (str1, str2) => {
    let cnt = 0;
    for(let i =0; i< str1.length;i++){
        if(cnt>1) return false;
        if(str1[i]!=str2[i]) cnt+=1;
    }
    if(cnt===1) return true;
    else return false;
}

function solution(begin, target, words) {
    var answer = 0;
    let q = new Array();
    let check = new Array(words.length);
    let minNum = 51;
    check.fill(50);
    q.push({cnt: 0, str: begin});
    while(q.length > 0){
        let cur = q.shift();

        if(cur.str==target && minNum > cur.cnt) {
            minNum = cur.cnt;
        }
        else {
            words.map((el, idx) => {
                if(isPossible(cur.str, el) && check[idx]>cur.cnt+1){
                    console.log(el)
                    check[idx] = cur.cnt+1;
                    q.push({cnt: cur.cnt+1, str: el})
                }
            })
        }
    }
    if(minNum===51) answer = 0;
    else answer = minNum;
   //console.log(answer);
    return answer;
}

solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]);