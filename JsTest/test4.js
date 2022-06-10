var p = new Promise((res, rej) => {
    setTimeout(() => {
      res("a")
    }, 1000)
    
})

var result = p.then(res => {
   console.log("p:",res); // "a"
  return res;
})

console.log(result) // Promise {<fulfilled>: "a"}

result.then(res => {
    console.log(result)
    console.log(res); // "a"
})