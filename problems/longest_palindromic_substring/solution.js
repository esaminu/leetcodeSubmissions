/**
 * @param {string} s
 * @return {string}
 */


var longestPalindrome = function(s) {
    if(s.length < 2) {
        return s
    }
    if(isPalindrome(s)){
        return s
    }
    let currLongest = ''
    for(let i = 0; i < s.length; i++ ) {
       for(let j = i + 1; j < s.length + 1; j++) {
           let str = s.substring(i,j)
           if(isPalindrome(str) && (str.length > currLongest.length)) {
               currLongest = str
           }
       }
    }
    return currLongest
};

function isPalindrome(str) {
    if(str.length === 1 ) {
        return true
    }
    if(str.length === 2) {
        return str[0] === str[1]
    }
    if(str[0] === str[str.length - 1]) {
        return true && isPalindrome(str.substring(1, str.length - 1))
    }
    return false
}