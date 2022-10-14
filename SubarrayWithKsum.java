import java.io.*;
import java.util.*;

public class SubarrayWithKsum {
    public static void main(String args[])throws IOException
    {
            int k=-10;
            int arr[]={10,2,-2,-20,10};
           
           // Naive approach
           System.out.println(subarraySum_Naive(arr, k));
           // O(n^2) approach
           System.out.println(subarraySum__n2(arr, k)); 
           // O(n) approach
           System.out.println(subarraySum__O_N(arr,k));
        
    }

    public static int subarraySum_Naive(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                {  
                     sum += nums[i];
                }
                if (sum == k)
                    count++;
            }
        }
        return count;
    }


    public static int subarraySum__n2(int[] nums, int k) {
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }



    public static int subarraySum__O_N(int[] nums, int k) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,1);
        int ssf=0;
        int count=0;
        for(int i=0;i<nums.length;i++)
        {
            ssf+=nums[i];
            
            if(hm.containsKey(ssf-k))
            {
                count+=hm.get(ssf-k);
                
            }
            
                hm.put(ssf,hm.getOrDefault(ssf,0)+1);
        }
        
        return count;
    }
}




   
