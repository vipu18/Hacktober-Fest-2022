class Solution {
private:
    unordered_map<int,pair<int,int>>pos;
    vector<vector<int>>mem;
    int solve(vector<int>&nums,int index,int numSlots,int config){
        if(index==nums.size()){
            return 0;
        } else if(mem[index][config]!=-1){
            return mem[index][config];
        } else {
            int ans=0;
            for(int i=1;i<=numSlots;i++){
                int first=pos[i].first,second=pos[i].second;
                if(((config>>first)&1)==0){
                    ans=max(ans,(nums[index]&i)+solve(nums,index+1,numSlots,config|(1<<first)));
                } else if(((config>>second)&1)==0){
                    ans=max(ans,(nums[index]&i)+solve(nums,index+1,numSlots,config|(1<<second)));
                }
            }
            return mem[index][config]=ans;
        }
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int diff=0;
        for(int i=1;i<=numSlots;i++){
            int first=i+diff;
            int second=i+diff+1;
            diff++;
            pos[i]=make_pair(first,second);
        }
        int n=nums.size();
        mem=vector<vector<int>>(n,vector<int>(1<<(2*numSlots)+1,-1));
        return solve(nums,0,numSlots,0);
    }
};
