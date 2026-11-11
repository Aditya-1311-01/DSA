class Solution {
public:
    int count(int i,vector<int>&dp){
        if(i<0)
        return 0;

        if(i==0)
        return 1;

        if(dp[i]!=-1)
        return dp[i];

        int onestep=count(i-1,dp);
        int twostep=count(i-2,dp);

        return dp[i]=onestep+twostep;
        
    }
    int climbStairs(int n) {

        vector<int>dp(n+1,-1);

        return count(n,dp);


        
        
        
    }
};