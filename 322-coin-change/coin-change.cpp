class Solution {
public:
    int count(int idx,int T,vector<int>&coins,vector<vector<int>>&dp){
        if(idx==0){
            if(T%coins[idx]==0)
            return T/coins[idx];
            else
            return 1e9;
        }
        // not take that coins
        if(dp[idx][T]!=-1) return dp[idx][T];
        int notTake=count(idx-1,T,coins,dp);

        int Take=INT_MAX;
        if(coins[idx]<=T)
        Take=1+count(idx,T-coins[idx],coins,dp);

        return dp[idx][T]=min(Take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=count(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        else return ans;
        
    }
};