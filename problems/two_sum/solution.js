/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    let obj = {};
    
    for(let i = 0; i<nums.length; i++) {
        let n = nums[i]
        if(obj[n] || obj[n] === 0) {
            return [obj[n], i]
        }
        obj[target - n] = i
    }
    
};