class Solution {
public:
    int f(int ind,int prev_ind,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==n) return 0;

        if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];

        int length=0+f(ind+1,prev_ind,n,nums,dp); // not take

        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        length=max(length,1+f(ind+1,ind,n,nums,dp));

        return dp[ind][prev_ind+1]=length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len=1;

        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }

        return len;
    }
};