class Solution {
public:
    void backtrack(int ind,vector<int>&nums,vector<int>&curr,vector<vector<int>>&result){
        if(curr.size()>=2){
            result.push_back(curr);
            
        }
        int n=nums.size();

        unordered_set<int>st;
        for(int i=ind;i<n;i++){
            if((curr.empty()||curr.back()<=nums[i])&& st.find(nums[i])==st.end()){
                curr.push_back(nums[i]);
                backtrack(i+1,nums,curr,result);
                curr.pop_back();

                st.insert(nums[i]);

            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr;
        
        backtrack(0,nums,curr,result);
        return result;
        
    }
};