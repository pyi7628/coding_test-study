function a() {

}
function aa() {

}

a.__proto__.getName = ()=> console.log("hia")
a.prototype.getPr = ()=> console.log("hiproa")
let b = new a()
let bb = a
let c = {}
c.__proto__.getNa = ()=> console.log("hic")
let d = {}
console.log("a: ", a.__proto__)
console.log("a: ", a.prototype)
console.log("aa: ", aa.__proto__)
console.log("b: ", b.__proto__)
// console.log("b: ", b.getName())
console.log(b.getPr())
console.log("c: ", c.__proto__.__proto__)
console.log("d: ", d.__proto__)
console.log({}.__proto__)