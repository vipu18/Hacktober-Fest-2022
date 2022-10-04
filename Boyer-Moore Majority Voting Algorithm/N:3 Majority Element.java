// Leetcode Problem Link: https://leetcode.com/problems/majority-element-ii/

// Boyer-Moore Majority Voting Algorithm (N/3)
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
        List<Integer> majorityElements = new ArrayList<>();
        
        int count1 = 0, count2 = 0, candidate1 = -1, candidate2 = -1, numsLength = nums.length;
        
        for(int index = 0; index < numsLength; index++){
            
            if(nums[index] == candidate1) count1++;
            else if(nums[index] == candidate2) count2++;
            else if(count1 == 0){
                candidate1 = nums[index];
                count1++;
            }
            else if(count2 == 0){
                candidate2 = nums[index];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
            
        }
        
        count1 = 0;
        count2 = 0;
        
        for(int index = 0; index < numsLength; index++){
            
            if(nums[index] == candidate1) count1++;
            else if(nums[index] == candidate2) count2++;
            
        }
        
        if(count1 > numsLength/3)
            majorityElements.add(candidate1);
        
        if(count2 > numsLength/3)
            majorityElements.add(candidate2);
        
        return majorityElements;
        
    }
}