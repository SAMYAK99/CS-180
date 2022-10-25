function diceLottery() {
    const inputNum = parseInt(document.querySelector('#inputNum').value);

    if(isNaN(inputNum) || inputNum === null || inputNum === ' ') {
        alert('Please, choose a number');
        return;
    }

    const diceNumber = Math.floor(Math.random() * 5 ) + 1;
    const dice = `./images/dice${diceNumber}.png`;
    document.querySelector('#dice').setAttribute('src', dice);

    const result = document.querySelector('#result');
    const award = document.querySelector('#award');
    
    if(inputNum === diceNumber) {
        result.innerHTML = 'You Won';
        
        switch(diceNumber) {
            case 1:
                award.setAttribute('src','./images/notebook.png');
                break;
            case 2:
                award.setAttribute('src','./images/mug.png');
                break;
            case 3:
                award.setAttribute('src','./images/coffee.png');
                break;
            case 4:
                award.setAttribute('src','./images/tshirt.png');
                break;
            case 5:
                award.setAttribute('src','./images/pen.png');
                break;
        }
        return;

    } else {
        result.innerHTML = 'You Lost';
        award.setAttribute('src','./images/trophy.png');
        return;
    }
}