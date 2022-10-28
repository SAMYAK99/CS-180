const convertDollarToRupee = () => {
    const currentDollarRatePerINR = 82.33;
    const dollarAmount = parseFloat(document.querySelector('#dollar').value);
    document.querySelector('#rupees').value = dollarAmount * currentDollarRatePerINR;
}