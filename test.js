//console.log({} === undefined);


let obj = { "repository": {} };
//console.log(obj['repository']['readme']);



function safelyGet(object, path) {
    const pathArr = path.split('.');
    let result = object;
    
    for(let i=0; i<pathArr.length; i+=1){
        // console.log("el:",  el);
        // console.log("result el:",  result[el] === undefined);
      if(result[pathArr[i]] === undefined){
        return undefined;
      }
      else {
        result = result[pathArr[i]];
      }
    }
    // pathArr.map((el) => {
    //     console.log("el:",  el);
    //     console.log("result el:",  result[el] === undefined);
    //   if(result[el] === undefined){
    //     return undefined;
    //   }
    //   else {
    //     result = result[el];
    //   }
    // });
    return result;
      // 입력해주세요
  }

  console.log(safelyGet(obj, "repository.readme"));