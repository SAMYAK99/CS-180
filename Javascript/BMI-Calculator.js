let mass = prompt("Enter your mass in KG: ");
let height = prompt("Enter your height in meters: ");

function BMI(mass, height){
  return mass/(height**2);
}
let calcBmi = BMI(mass,height);
console.log(`Your BMI is ${calcBmi}.`);
if(calcBmi<18.5){
  console.log("You are underweight.");
}
else if(calcBmi>=18.5 && calcBmi<25){
  console.log("You are normal weight.");
}
else if(calcBmi>=25 && calcBmi<30){
  console.log("You are pre-obesity.");
}
else if(calcBmi>=30 && calcBmi<35){
  console.log("You are obesity class I.");
}
else if(calcBmi>=35 && calcBmi<40){
  console.log("You are obesity class II.");
}
else{
  console.log("You are obesity class III.");
}
