class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;

        int maxlength=0;
        int count0=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==0)
            count0++;

            while(count0>k){
                if(nums[i]==0){
                    count0--;
                }
                i++;
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }

        return maxlength;

   }
};