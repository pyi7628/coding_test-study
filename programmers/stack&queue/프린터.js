function solution(priorities, location) {
    let arr = priorities.slice();
    arr[location] = -1;
    var answer = 0;
    let cnt = {};
    let curPri = 9;
    let printCnt = 0;
    priorities.map((el) => {
        if (cnt[el]==undefined) cnt[el] = 0;
        cnt[el]+=1;
    });
    console.log(cnt);

    while(1) {
        while(cnt[curPri]===undefined || cnt[curPri]===0 ) curPri-=1;
        console.log(curPri);
        let curItem = priorities.shift();
        let curState = arr.shift();
        if(curItem===curPri) {
            printCnt+=1;
            if(curState===-1) {
                answer = printCnt;
                break;
            }
            cnt[curPri]-=1;
        }
        else {
            priorities.push(curItem);
            arr.push(curState);
        }
    }
    return answer;
}

// function solution(priorities, location) {
//     var list = priorities.map((t,i)=>({
//         my : i === location,
//         val : t
//     }));
//     var count = 0;        
//     while(true){
//         var cur = list.splice(0,1)[0];        
//         if(list.some(t=> t.val > cur.val )){
//             list.push(cur);                        
//         }
//         else{            
//             count++;
//             if(cur.my) return count;
//         }
//     }
// }