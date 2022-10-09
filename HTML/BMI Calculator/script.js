
function calculate_BMI() {
    var weight = document.getElementById("weightField").value;
    var height = document.getElementById("heightField").value;
    var output1 = document.getElementById("output1");
    var output2 = document.getElementById("output2");

    var bmi = weight / (height * height);
    output1.innerHTML = "your BMI is" + bmi;

    if (bmi < 18.5) {
        output2.innerHTML = "INCREASE YOUR WEIGHT";
    } else if (bmi < 25) {
        output2.innerHTML = "You are all good";
    } else {
        output2.innerHTML = "DECREASE YOUR WEIGHT";
    }
}
