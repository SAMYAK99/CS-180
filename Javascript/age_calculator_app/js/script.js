let currentDate = new Date().toLocaleDateString();
let [dd,mm,yyyy] = currentDate.split('/');

const dob = document.querySelector('#dob');

//setting the current date as max date
dob.setAttribute('max',`${mm}/${dd}/${yyyy}`);

function calcAge() {
    let birthDate = document.querySelector('#dob').value;
    let [year,month,day] = birthDate.split('-');
    
    let dob = new Date(`${month}/${day}/${year}`);  
    let month_diff = Date.now() - dob.getTime();  
    let age_date = new Date(month_diff);
    let year_ = age_date.getUTCFullYear();
    let userAge = Math.abs(year_ - 1970);
    
    document.querySelector('#userAge').value = userAge;
}