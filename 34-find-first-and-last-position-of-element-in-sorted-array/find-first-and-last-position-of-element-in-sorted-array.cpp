class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        int low=0,high=nums.size()-1;
        int first=-1;
        int last=-1;

        while(low<=high){
            int guess=(high-low)/2+low;

            if(nums[guess]<target)
            low=guess+1;

            else if(nums[guess]==target){
                first=guess;
                high=guess-1;
            }

            else{
                high=guess-1;
            }
        }

        // last position
        low=0,high=nums.size()-1;
        while(low<=high){
            int guess=low+(high-low
            )/2;
            if(nums[guess]<target)
            low=guess+1;

            else if(nums[guess]==target){
                last=guess;
                low=guess+1;
                
            }

            else{
                high=guess-1;
            }
        }

        ans[0]=first;
        ans[1]=last;

        return ans;
        
    }
};