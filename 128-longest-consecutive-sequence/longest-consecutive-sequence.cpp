class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        int cnt=0;
        int prevsmallest=INT_MIN;

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1==prevsmallest){
                cnt+=1;
                prevsmallest=nums[i];
            }
            if(nums[i]!=prevsmallest){
                cnt=1;
                prevsmallest=nums[i];
            }
            longest=max(longest,cnt);
        }

        
        return longest;
    }
};