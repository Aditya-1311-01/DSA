class Solution {
public:
    int best(int ind,bool buy,int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=n)
        return 0;

        if(dp[ind][buy]!=-1)
        return dp[ind][buy];

        int profit=0;

        if(buy){
            profit=max(-prices[ind]+best(ind+1,0,n,prices,dp),best(ind+1,1,n,prices,dp));
        }
        else // sell
        {
            profit=max(prices[ind]+best(ind+2,1,n,prices,dp),best(ind+1,0,n,prices,dp));
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return best(0,1,n,prices,dp);
    }
};