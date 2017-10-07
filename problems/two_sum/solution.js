/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var length1 = nums.length
    var length = length1 - 1
    for(i=0;i<length;i++){
        for(j=i+1;j<length1;j++){
            if(nums[i] + nums[j] === target) {
                return [i,j]
            }
        }
    }
};