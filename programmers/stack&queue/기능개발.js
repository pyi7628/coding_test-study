function solution(progresses, speeds) {
    let cnt = 0;
    let answer = []
    while(0!==progresses.length) {
        progresses = progresses.map((el, idx) => {
            return el+speeds[idx];
        });

        while(progresses[0]>=100){
            cnt+=1;
            progresses.shift();
            speeds.shift();
            //console.log(temp)
        }
        if(cnt!==0) answer.push(cnt);
        if(cnt!==0) console.log(cnt);
        cnt=0;

    }
    return answer;
}
