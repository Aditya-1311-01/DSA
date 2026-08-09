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
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
        
    }
};