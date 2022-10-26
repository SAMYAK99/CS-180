// function to check palindrome
function checkPalindrome(str) {
    
    // applying split, revere and join
    const reversedString = str.split('').reverse().join('');
    if(str === reversedString)
          return true;
    else
          return false;
}
