/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let currMax = 0
    for(let i = 0; i < height.length; i++ ) {
        for(let j = 0; j < height.length; j++ ) {
            if(i === j) {
                continue;
            }
            let area = Math.abs(i - j) * Math.min(height[i], height[j])
            if(area > currMax) {
                currMax = area
            }
        }
    }
    return currMax
};