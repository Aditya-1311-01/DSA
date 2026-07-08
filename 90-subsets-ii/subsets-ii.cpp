class Solution {
public:
    void find(int idx,vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp){
        ans.push_back(temp);

        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i-1]==nums[i]) continue; // duplicate add nhi krega

            temp.push_back(nums[i]);
            find(i+1,nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;

        find(0,nums,ans,temp);

        return ans;
        
    }
};