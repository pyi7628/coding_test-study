// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    let arr = [];
    A.map((el, idx) => {
        arr.push({size: el, index: idx, p1: idx-el, p2: idx+el});
        return '';
    })
    arr.sort((a, b)=> {
        return b.size-a.size; // 내림차순
    })
    let arrSize = arr.length;
    let cnt = 0;
    arr.map((el, idx)=> {
         let {size, index} = el;
         for(let i = idx+1; i< arrSize; i++){
            if(size+index >= arr[i].size+arr[i].index && index - size <= arr[i].size+arr[i].index
                || size+index >= arr[i].index-arr[i].size && index - size <= arr[i].index-arr[i].size) {
                cnt+=1;
                console.log(arr[i]);
            }
            
         }
        return '';
    })
    console.log(cnt)
    return cnt;

}

solution([1, 5, 2, 1, 4, 0]);


// #1 correct: 100%, perform: 75% => n^2
// function solution(A) {
//     // write your code in JavaScript (Node.js 8.9.4)
//     let arr = [];
//     A.map((el, idx) => {
//         arr.push({size: el, index: idx});
//         return '';
//     })
//     arr.sort((a, b)=> {
//         return b.size-a.size; // 내림차순
//     })
//     let arrSize = arr.length;
//     let cnt = 0;
//     arr.map((el, idx)=> {
//          let {size, index} = el;
//          for(let i = idx+1; i< arrSize; i++){
//             if(size+index >= arr[i].size+arr[i].index && index - size <= arr[i].size+arr[i].index
//                 || size+index >= arr[i].index-arr[i].size && index - size <= arr[i].index-arr[i].size) {
//                 cnt+=1;
//             }
            
//          }
//         return '';
//     })
//     return cnt;

// }