/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(str) {
    let freq = {};
    let currLongest = Number.MIN_VALUE;
    let windowStart = 0, windowEnd = 0;
  
    while(windowEnd <= str.length) {
        if(!freq[str[windowEnd]]) {
          currLongest = Math.max(currLongest, windowEnd - windowStart);
          freq[str[windowEnd++]] = 1;
        } else {
          currLongest = Math.max(currLongest, windowEnd - windowStart);
          freq[str[windowStart++]]-=1;
        }
    }
    return currLongest;
};