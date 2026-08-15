class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        int jumps=0;
        while(right<n-1){
            int farthest=0;
            for(int i=left;i<=right;i++){
                farthest=max(i+nums[i],farthest);
            }
            left=right+1;
            right=farthest;
            jumps=jumps+1;
        }
        return jumps;
    }
};