class Solution {
public:
    void find(int idx,vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp){
        int n=nums.size();
       
       if(idx==n){
        ans.push_back(temp);
        return;
       }

       temp.push_back(nums[idx]);
       find(idx+1,nums,ans,temp);
       temp.pop_back();

       while(idx<n-1 &&nums[idx]==nums[idx+1]){
        idx++;
       }
       find(idx+1,nums,ans,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;

        find(0,nums,ans,temp);

        return ans;
        
    }
};