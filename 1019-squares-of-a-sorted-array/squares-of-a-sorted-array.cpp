class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;

        int k = n - 1;

        while (left <= right) {

            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                ans[k] = leftSquare;
                left++;
            }
            else {
                ans[k] = rightSquare;
                right--;
            }

            k--;
        }

        return ans;
    }
};