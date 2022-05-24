/*
setTimeout(function() {
    console.log(111)
}, 0);
setTimeout(function() {
    console.log(333)
}, 1000);
new Promise(function(resolve){
    console.log(444);
    resolve();
    console.log(555);
}).then(function(){
    console.log(666);
});
console.log(777);
async function test1() {
    console.log("test1");
    await test2();
    console.log("test1 last");
}
async function test2() {
    console.log("test2");
}
test1();
*/

setImmediate(function(){
    console.log(1);
},0);
setTimeout(function(){
    console.log(2);
},0);
new Promise(function(resolve){
    console.log(3);
    resolve();
    console.log(4);
}).then(function(){
    console.log(5);
});
console.log(6);
process.nextTick(function(){
    console.log(7);
});
console.log(8);