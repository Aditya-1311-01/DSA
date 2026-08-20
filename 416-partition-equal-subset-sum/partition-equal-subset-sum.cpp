class Solution {
public:
    bool f(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(idx==0) return (arr[0]==target);

        if(dp[idx][target]!=-1)  return dp[idx][target];

        bool not_take=f(idx-1,target,arr,dp);
        bool take=false;
        if(target>=arr[idx])
        take=f(idx-1,target-arr[idx],arr,dp);

        return dp[idx][target]=take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)
        sum+=it;

        int n=nums.size();
        if(sum%2!=0) return false;

        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return f(n-1,target,nums,dp);

        
    }
};