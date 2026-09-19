class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int ans=0;
        int min=nums[0];
        for(int i=1;i<n;i++){
            ans+=(nums[i]-min);
        }

        return ans;

    }
};