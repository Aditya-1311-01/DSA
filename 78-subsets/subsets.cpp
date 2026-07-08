class Solution {
public:

    void find(int idx,int n,vector<int>&nums,vector<vector<int>>&ans,vector<int>&diary){

        if(idx==n){
            ans.push_back(diary);
            return;
        }

        diary.push_back(nums[idx]);
        find(idx+1,n,nums,ans,diary);
        diary.pop_back();

        find(idx+1,n,nums,ans,diary);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>diary;
        int n=nums.size();
        find(0,n,nums,ans,diary);

        return ans;
        
    }
};