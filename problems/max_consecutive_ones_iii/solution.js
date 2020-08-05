/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var longestOnes = function(arr, k) {
        if(k >= arr.length) {
            return arr.length;
        }
      let zeros = 0;
      let currLongest = Number.MIN_VALUE;
      let windowStart = 0, windowEnd = 0;
        
      while(windowEnd < arr.length) {
        if(arr[windowEnd] || (zeros < k)) {
          zeros += (arr[windowEnd] ? 0 : 1);
          windowEnd++;
        } else {
          if(!arr[windowStart]) {
            zeros--;
          }
          windowStart++;
        }
        currLongest = Math.max(windowEnd - windowStart, currLongest)
      }
      return currLongest;
};