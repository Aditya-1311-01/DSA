class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=-1;
        int low=0,high=nums.size()-1;
        int n=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>nums[n]){
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }

        return nums[ans];
        
    }
};