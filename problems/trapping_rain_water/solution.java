class Solution {
    public int trap(int[] height) {
        int currentArea = 0;
        
        for(int i = 0; i < height.length; i++) {
            int leftMax = 0;
            int rightMax = 0;
           for(int j = 0; j < i; j++) {
               if(height[j] > leftMax) {
                   leftMax = height[j];
               } 
           }
            for(int k = i; k < height.length; k++ ) {
                 if(height[k] > rightMax) {
                   rightMax = height[k];
               }
            }
            int waterAbove = Math.max(Math.min(leftMax, rightMax) - height[i], 0);
            currentArea = currentArea + waterAbove;
        }
        
        return currentArea;
        
    }
}