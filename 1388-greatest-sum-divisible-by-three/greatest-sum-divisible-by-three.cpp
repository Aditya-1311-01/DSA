class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, vector<int>& nums, int rem) {

        if(i < 0) {
            if(rem == 0)
                return 0;

            return -1e9;
        }

        if(dp[i][rem] != -1)
        return dp[i][rem];

        
        int choose = nums[i] +f(i - 1, nums, (rem + nums[i]) % 3);

        
        int not_choose =f(i - 1, nums, rem);

        return dp[i][rem] = max(choose, not_choose);
    }

    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();

        dp.assign(n, vector<int>(3, -1));

        return f(n - 1, nums, 0);
    }
};