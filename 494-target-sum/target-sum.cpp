class Solution {
public:
    int findways(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(ind==0){
            if(sum==0 && arr[0]==0)
            return 2;
            
            if(sum==0 || sum==arr[0])
            return 1;
            
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notTake=findways(ind-1,sum,arr,dp);
        
        int take=0;
        if(arr[ind]<=sum)
        take=findways(ind-1,sum-arr[ind],arr,dp);
        
        return dp[ind][sum]=take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        for(auto &it:nums){
            totalsum+=it;
        
        }
        int n=nums.size();
        int T=(totalsum-target)/2;
        
        if(totalsum-target<0 || (totalsum-target)%2 ) return 0;
        vector<vector<int>>dp(n,vector<int>(T+1,-1));
        
        return findways(n-1,T,nums,dp);

        
    }
};