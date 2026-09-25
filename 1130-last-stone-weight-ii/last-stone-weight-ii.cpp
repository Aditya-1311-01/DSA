class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total_sum=0;

        int n=stones.size();
        for(auto it:stones){
            total_sum+=it;
        }
        int k=total_sum;

        vector<vector<int>>dp(n,vector<int>(total_sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(stones[0]<=k) dp[0][stones[0]]=true;

        for(int idx=1;idx<n;idx++){
            for(int sum=1;sum<=k;sum++ ){

                bool not_take=dp[idx-1][sum];
                bool take=false;
                if(stones[idx]<=sum){
                    take=dp[idx-1][sum-stones[idx]];
                }

                dp[idx][sum]=take || not_take;
            }
        }

        int ans=INT_MAX;

        for(int sum=0;sum<=k;sum++){
            if(dp[n-1][sum]!=false){
                ans=min(ans, abs(sum -(k-sum)));
            }
        }

        return ans==INT_MAX? 0: ans;


        
    }
};