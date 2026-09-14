class Solution {
public:
    int f(int i, vector<int>& nums, unordered_map<int,int>& mp,vector<int>&dp) {

        if(i < 0)
            return 0;

        if(dp[i]!=-1) return dp[i];

        int not_choose = f(i - 1, nums, mp,dp);

        
        int x = nums[i];

        
        int points = x * mp[x];

        
        int j = i;
        while(j >= 0 && nums[j] == x) {
            j--;
        }

        
        while(j >= 0 && nums[j] == x - 1) {
            j--;
        }

        int choose = points + f(j, nums, mp,dp);

        return dp[i]=max(choose, not_choose);
    }

    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        unordered_map<int,int> mp;

        for(auto x : nums)
            mp[x]++;
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(nums.size() - 1, nums, mp,dp);
    }
};