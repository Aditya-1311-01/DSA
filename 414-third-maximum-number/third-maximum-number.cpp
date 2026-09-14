class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());

         int count=2;
        for(int i=0;i<nums.size();i++){
            if(count==0)
                return nums[i];
            if(i<nums.size()-1 && nums[i]!=nums[i+1])
            count--;
         }
        return nums[0];
    }
};