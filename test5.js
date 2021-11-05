var p1 = new Promise((res, rej) => {
    setTimeout(() => {
      res("a")
    }, 1000)
    
})
var p2 = new Promise((res, rej) => {
    setTimeout(() => {
      res("a")
    }, 1000)
    
})

p1.then(res => {
   console.log("p1:",res); // "a"
  return res;
})
p2.then(res => {
    console.log("p2:",res); // "a"
   return res;
 })
 

// console.log(result) // Promise {<fulfilled>: "a"}

// result.then(res => {
//     console.log(result)
//     console.log(res); // "a"
// })