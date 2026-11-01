class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();

        for(int i=0;i<=n-3;i++){
             if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target=-nums[i];
            int left=i+1,right=n-1;

            while(left<right){
                if(nums[left]+nums[right]==target){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    while(left<right && nums[left-1]==nums[left]){
                        left++;
                    }
                    while(left<right && nums[right+1]==nums[right]){
                        right--;
                    }
                }
                else if(nums[left]+nums[right]<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return ans;
    }
};