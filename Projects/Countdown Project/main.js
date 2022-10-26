let DaysItem=document.querySelector("#days");
let hoursItem=document.querySelector("#hours");
let minItem=document.querySelector("#min");
let secItem=document.querySelector("#sec");

let countdown=()=>{
    let futureDate=new Date("1 jan 2023");
    let currDate=new Date();
    let myDate=futureDate-currDate;
    // console.log(myDate);
    let days=Math.floor(myDate/1000/60/60/24);

    let hours=Math.floor(myDate/1000/60/60)%24;

    let min=Math.floor(myDate/1000/60)%60;

    let sec=Math.floor(myDate/1000)%60;
    DaysItem.innerHTML=days;
    hoursItem.innerHTML=hours;
    minItem.innerHTML=min;
    secItem.innerHTML=sec;

}
countdown()

setInterval(countdown,1000)