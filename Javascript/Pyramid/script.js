var displayBox = document.querySelector('.display-box');

function formPyramid(n) {
    displayBox.replaceChildren()
    const midPoint = Math.floor((2 * n - 1) / 2);
    
    for(let  row = 0; row < n; row++) {
        let rowDiv = document.createElement('div');
        rowDiv.className = 'row-div';
        displayBox.appendChild(rowDiv);

        for (let col = 0; col < (n * 2) - 1; col++) {
            if ( midPoint - row <= col && midPoint + row >= col) {
                const squareBox = document.createElement('div');
                squareBox.className = "square-box";
                rowDiv.append(squareBox)
            }
            else {
                const hollowBox = document.createElement('div');
                hollowBox.className = "hollow-box";
                rowDiv.append(hollowBox)
            }
        }
    }
}

window.onload = formPyramid(6);