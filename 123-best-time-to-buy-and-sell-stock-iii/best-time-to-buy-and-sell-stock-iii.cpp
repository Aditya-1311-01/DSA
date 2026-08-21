class Solution {
public:
    int best(int idx,int buy,int cap,int n,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(idx==n) return 0;
        if(cap==0) return 0;

        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];

        if(buy){
            return dp[idx][buy][cap]=max(-prices[idx]+best(idx+1,0,cap,n,prices,dp),
           0+ best(idx+1,1,cap,n,prices,dp)

            );
        }
        else{
            return dp[idx][buy][cap]=max(prices[idx]+best(idx+1,1,cap-1,n,prices,dp),
            best(idx+1,0,cap,n,prices,dp)
            
            );
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return best(0,1,2,n,prices,dp);
        
    }
};