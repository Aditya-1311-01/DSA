class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=nums[0],min_sum=nums[0],min_end=nums[0];
        int max_sum=nums[0],max_end=nums[0];
        for(int i=1;i<nums.size();i++){
            max_end=max(max_end+nums[i],nums[i]);
            max_sum=max(max_sum,max_end);

            min_end=min(min_end+nums[i],nums[i]);
            min_sum=min(min_sum,min_end);

            sum+=nums[i];
        }

        if(max_sum<0) // if all elements are negative
        return max_sum;

        int case1=max_sum;
        int case2=sum-min_sum;

        return max(case1,case2);

        
    }
};