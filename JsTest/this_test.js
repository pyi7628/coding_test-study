// 웹 브라우저에서는 window 객체가 전역 객체
/*
var a = 1;
console.log(this === global); 
console.log( globalThis); // true

a = 37;
console.log(window.a); // 37

this.b = "MDN";
console.log(window.b)  // "MDN"
console.log(b)         // "MDN"

*/

/*
function f1() {
    return this;
  }
  
  // 브라우저
//   f1() === window; // true
  
  // Node.js
  console.log(f1() === global); // true

  console.log(f1());
  */

/*var globalObject = this;
var foo = (() => this);
function f1() {
    return this;
  }
console.log(foo() === globalObject); // true
console.log(f1() === globalObject); // true
*/

const counter = (function () {
  let num = 0;
  return {
    increase() {
      console.log(this);
      return ++num;
    },
    decrease() {
      return num > 0 ? --num : 0;
    }
  };
  // return (function () {
  //   console.log(this);
  //   return ++num;
  // })
}());

console.log(counter.increase());