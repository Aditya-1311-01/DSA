class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int nonzero=0;
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];

            if(nums[i]!=0)
            nonzero++;
        }

        if(nonzero==0)
        return 0;

        if(x)
        return nums.size();
        else
        return nums.size()-1;
        
    }
};