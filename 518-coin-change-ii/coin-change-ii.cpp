class Solution {
public:
    int count(int idx,int T,vector<int>&coins,vector<vector<int>>&dp){
        if(idx==0){
            return T%coins[idx]==0;
        }
        if(dp[idx][T]!=-1) return dp[idx][T];
        int notTake=count(idx-1,T,coins,dp);
        int Take=0;
        if(coins[idx]<=T)
        Take=count(idx,T-coins[idx],coins,dp);

        return dp[idx][T]=Take+notTake;
    }
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return count(n-1,amount,coins,dp);
        
    }
};