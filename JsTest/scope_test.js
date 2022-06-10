// 전역변수, 지역변수 호이스팅 테스트
/*var x = 'global';

function foo() {
    console.log(x); // undefined
    var x = 'local';
}

foo();
console.log(x); // global
*/



// 렉시컬 스코프 테스트

var x = 1;

function foo() {
	var x = 10;
	bar();
}
function bar() {
	console.log(x);
}

foo();
console.log(x);