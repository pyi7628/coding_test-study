// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(N, A) {
    // write your code in JavaScript (Node.js 8.9.4)
    let arr = new Array(N);
   
    let maxNum = 0;
    let fillNum = 0;
    arr.fill(0);
    A.map((el)=> {
        if(el==N+1) {
            fillNum = maxNum;
        }
        else {
            if(fillNum> arr[el-1]) arr[el-1] = fillNum;
            arr[el-1]+=1;
         
            if(maxNum<arr[el-1]) maxNum = arr[el-1];
        }
        return '';
    });
    arr.map((el, index)=> {
        if(arr[index]<fillNum) arr[index] = fillNum;
        return '';
    });
    return arr;
}