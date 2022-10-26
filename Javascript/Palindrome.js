const palindrome = "madam";
const notAPalindrome = "sir";

function isPalindrome(string) {
    return string.split("").reverse().join("") === string;
}

console.log(isPalindrome(palindrome));
console.log(isPalindrome(notAPalindrome));
