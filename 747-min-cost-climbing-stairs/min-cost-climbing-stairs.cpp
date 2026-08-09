class Solution {
public:
    int mincost(int n,vector<int>&cost,vector<int>&dp){
        if(n<=1)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=min(cost[n-1]+mincost(n-1,cost,dp),cost[n-2]+mincost(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        
        int prev1=0,prev=0,curr;
        for(int i=2;i<=n;i++){
            curr=min(cost[i-1]+prev,cost[i-2]+prev1);
            prev1=prev;
            prev=curr;
        }
        return curr;
        
    }
};