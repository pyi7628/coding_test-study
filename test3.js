function solution(paths) {
    var answer = '';
    const allPaths = findAllPath(paths);
    console.log(allPaths);
    const stack  = [];
    for(ap of allPaths) {
      if(ap[0] == '.'){
        let removeCnt = ap.length - 1;
        while(removeCnt--){
          stack.pop();
        }
      }
      else if(ap!=='') {
        stack.push(ap);
      }
      console.log(stack);
    }
    for(s of stack) {
      answer+="/";
      answer+=s;
    }
    return answer;
}

function findAllPath(paths) {
  let newPaths = [];
  //let curP;
  for(p of paths) {
      newPaths = newPaths.concat(p.split('/'));
      console.log('p: ', p);
      console.log(p.split('/'));
  }
  return newPaths;

}

console.log(solution(
    ["/foo", "bar", "baz/asdf", "q", ".."]));