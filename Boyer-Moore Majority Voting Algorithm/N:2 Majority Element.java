// Leetcode Problem Link: https://leetcode.com/problems/majority-element/

// Boyer-Moore Majority Voting Algorithm (N/2)
class Solution {
    public int majorityElement(int[] nums) {
        
        int count = 0, candidate = -1, numsLength = nums.length;
        
        for(int index = 0; index < numsLength; index++){
            
            if(count == 0){
                candidate = nums[index];
                count++;
            }
            
            else{
                if(nums[index] == candidate) count++;
                else count--;
            }
        }
        
        count = 0;
        for(int index = 0; index < numsLength; index++){
            if(nums[index] == candidate) count++;
        }
        
        if(count > numsLength/2)
            return candidate;
        
        return -1;
        
    }
}