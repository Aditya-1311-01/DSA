class Solution {
public:
    int M=1e9+7;
    int solve(int len, int zero, int one, int low, int high ,vector<int>&dp) {

        if (len > high)
            return 0;

        int ans = 0;

        if (len >= low && len <= high) {
            ans = 1;
        }

        if(dp[len]!=-1)
        return dp[len];

        int append_zero = solve(len + zero, zero, one, low, high,dp);

        int append_one = solve(len + one, zero, one, low, high,dp);

        return dp[len]=(ans + append_zero + append_one)%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return solve(0, zero, one, low, high,dp);
    }
};