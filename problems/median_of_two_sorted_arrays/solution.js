/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var sorted = nums1.concat(nums2).sort((a,b)=>a-b)
    var length = sorted.length
    return length % 2 != 0 ? sorted[(length/2)-0.5] : (sorted[(length/2)-1] + sorted[length/2])/2
};