function restrictBackButton() {
    window.history.forward();
}

setTimeout("restrictBackButton()", 0);
    window.onunload = function() {
        null
};

let paraHeader = document.getElementById('paraHeader');

