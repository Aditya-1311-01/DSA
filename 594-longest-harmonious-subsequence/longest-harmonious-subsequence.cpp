class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0, j = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int n = nums.size();

        while (j < n) {

            maxi = nums[j];
            mini = nums[i];

            // If difference becomes greater than 1,
            // move left pointer
            while (maxi - mini > 1) {
                i++;

                mini = nums[i];
            }

            // Valid harmonious subsequence
            if (maxi - mini == 1) {
                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};