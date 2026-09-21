class Solution {
public:

    vector<vector<long long>> dp;
    vector<int> nums;
    int k;

    void solve(int i) {

        // Base case
        if (i == 0) {
            int rem = nums[0] % k;
            dp[0][rem] = 1;
            return;
        }

        // Pehle previous index calculate karo
        solve(i - 1);

        // Current element se new subarray
        int rem = nums[i] % k;
        dp[i][rem]++;

        // Previous subarrays ko current element ke saath extend karo
        for (int r = 0; r < k; r++) {

            int newRem = (r * rem) % k;

            dp[i][newRem] += dp[i - 1][r];
        }
    }

    vector<long long> resultArray(vector<int>& nums, int k) {

        this->nums = nums;
        this->k = k;

        int n = nums.size();

        dp.assign(n, vector<long long>(k, 0));

        // Top-down recursion
        solve(n - 1);

        // Final answer
        vector<long long> ans(k, 0);

        for (int i = 0; i < n; i++) {
            for (int r = 0; r < k; r++) {
                ans[r] += dp[i][r];
            }
        }

        return ans;
    }
};