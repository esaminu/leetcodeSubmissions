/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // if (s.length === 0) return 0
    // if (s.length === 1) return 1
    var lengths = [];
    var letters = [];
    for(i=0;i<s.length;i++){
        if(letters.length == 0 || !letters.includes(s[i])){
            letters.push(s[i])
        } else if(letters.includes(s[i])){
            lengths.push(letters.length)
            letters = letters.indexOf(s[i]) === letters.length - 1 ? [s[i]] : letters.slice(letters.indexOf(s[i]) + 1, letters.length).concat([s[i]])
        }
    }
    var max  = Math.max(...lengths)
    return  max > letters.length ? max : letters.length
    
};