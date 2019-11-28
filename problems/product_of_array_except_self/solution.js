/**
 * @param {number[]} nums
 * @return {number[]}
 */

var productExceptSelf = function(nums) {
    let leftArr = [1]
    let rightArr = []
    nums.forEach((n, i) => {
        if(i === 0) {
            return
        }
        leftArr.push(leftArr[i - 1] * nums[i - 1])
    })
    for(i = nums.length - 1; i >=0; i--) {
        if(i === nums.length - 1) {
            rightArr[i] = 1
            continue
        }
        rightArr[i] = rightArr[i + 1] * nums[i + 1]
    }
    return nums.map((a, i) => leftArr[i] * rightArr[i])
};
                    
function product(arr) {
    return arr.reduce((acc, curr) => acc * curr, 1)  
}