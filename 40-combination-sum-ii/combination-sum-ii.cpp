class Solution {
public:

    void find(int idx,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        // base condition hai
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if (idx >= arr.size() || target < 0) {
            return;
        }


        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            find(idx+1,target-arr[idx],arr,ans,ds);
            ds.pop_back();

        }
        while(idx+1<arr.size()&&arr[idx]==arr[idx+1]){
            idx++;
        }
        find(idx+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,target,candidates,ans,ds);
        return ans;
        
    }
};