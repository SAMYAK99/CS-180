const conversion_rate_api = "https://api.exchangerate-api.com/v4/latest/USD";

const convertDollarToRupee = async () => {
    const response = await fetch(conversion_rate_api);
    let data =  await response.json();
    const dollarAmount = parseFloat(document.querySelector('#dollar').value);
    document.querySelector('#rupees').value = parseFloat(dollarAmount * data.rates.INR).toFixed(2);
}
