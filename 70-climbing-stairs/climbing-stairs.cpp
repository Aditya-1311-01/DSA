class Solution {
public:
    int count(int i,int n,vector<int>&dp){
        if(i==n)
        return 1;
        if(i>n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        return dp[i]=count(i+1,n,dp)+count(i+2,n,dp);
    }
    int climbStairs(int n) {


        
        vector<int>dp(n+2,-1);
        int curr,next=1,next2=0;
        for(int i=n-1;i>=0;i--){
            curr=next+next2;
            next2=next;
            next=curr;
        }
        return curr;
        
    }
};