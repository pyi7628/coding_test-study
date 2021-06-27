// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A, K) {
    // write your code in JavaScript (Node.js 8.9.4)
    const arrSize = A.length;

    const rotateNum = K % arrSize;

    let result = new Array(arrSize);
    result.fill(0);
    
    A.map((el, index)=> {
        result[(rotateNum+index)%arrSize] = el;
        return '';
    })
    return result;
}
