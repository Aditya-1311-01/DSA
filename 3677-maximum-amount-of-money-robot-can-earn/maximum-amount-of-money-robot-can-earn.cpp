class Solution {
public:
    int f(int i,int j,int normalization,vector<vector<int>>&coins,vector<vector<vector<int>>>&dp){

        if(i<0 || j<0) return -1e9;

        if(i==0 && j==0){
            if(coins[i][j]<0 && normalization>0)
            return 0;

            return coins[i][j];
        }

        if(dp[i][j][normalization]!=-1e9) return dp[i][j][normalization];

        int up=-1e9;
        int left=-1e9;

        up=coins[i][j]+f(i-1,j,normalization,coins,dp);
        left=coins[i][j]+f(i,j-1,normalization,coins,dp);

        if(coins[i][j]<0 && normalization>0){
            up=max(up,f(i-1,j,normalization-1,coins,dp));

            left=max(left,f(i,j-1,normalization-1,coins,dp));
        }

        return dp[i][j][normalization]=max(up,left);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,-1e9)));

        return f(m-1,n-1,2,coins,dp);
        
    }
};