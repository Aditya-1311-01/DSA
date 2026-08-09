class Solution {
public:
    int robbery(int index,vector<int>&nums,vector<int>&dp){
        if(index==0)
        return nums[0];

        if(index==1)
        return max(nums[0],nums[1]);

        if(dp[index]!=-1)
        return dp[index];

        return dp[index]=max(nums[index]+robbery(index-2,nums,dp),robbery(index-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int curr=0;
        int prev=max(nums[0],nums[1]);
        int prev2=nums[0];

        for(int i=2;i<n;i++){
            curr=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};