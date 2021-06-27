// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

let str = "";

const ten2two = num => {
    let temp = num;
    for(let i = 32; i > 0; i--){
        if(temp >= Math.pow(2, i-1)){
            temp-= Math.pow(2, i-1);
            str += "1";
        }
        else str+="0";
    }
}
function solution(N) {

    const regex = /10+1/;
    ten2two(N);
    let maxNum = 0;
    while(1) {
        let matchStr = regex.exec(str);
        if(matchStr == null) break;
        else {
            str = str.replace(regex, "1");
            if(matchStr[0].length-2 > maxNum) maxNum = matchStr[0].length - 2;
        }
    }
    return maxNum;

}

console.log(solution(328));
