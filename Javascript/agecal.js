var age = prompt("Enter your age");

if(age<0){
	console.log("ERROR!");
} if(age==21){
	console.log("Happy 21st birthday!!");
} if(Math.sqrt(age) === Math.round(Math.sqrt(age))){
	console.log("Perfect square!");
}if(age%2!=0){
	console.log("You age is odd!");
}