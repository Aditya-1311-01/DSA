class Solution {
public:
    int fibon(int n,vector<int>&dp){
        if(n<=1)
        return n;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=fibon(n-1,dp)+fibon(n-2,dp) ;// result store kr rhe
    }
    
    int fib(int n) {
        

        if(n<=1)
        return n;

        int prev2=0,prev=1,curr;
        for(int i=2;i<=n;i++){
            curr=prev+prev2;
            prev2=prev;
            prev=curr;

        }
        return curr;
        
        
        
        
    }
};