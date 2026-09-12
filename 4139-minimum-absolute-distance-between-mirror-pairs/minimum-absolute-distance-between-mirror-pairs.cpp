class Solution {
public:
    int reverse(int n) {
        int ans = 0;

        while (n > 0) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }

        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {

            // Previous number i such that
            // reverse(nums[i]) == nums[j]
            if (mp.find(nums[j]) != mp.end()) {
                ans = min(ans, j - mp[nums[j]]);
            }

            // Store reverse(nums[j]) for future elements
            mp[reverse(nums[j])] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};