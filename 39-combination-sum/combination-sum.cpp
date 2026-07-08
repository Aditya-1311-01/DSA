class Solution {
public:
    void find(int idx,int target,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&diary){

        // base case hai
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(diary);
            }
            return;
        }
        // pick up the element
        if(candidates[idx]<=target){
            diary.push_back(candidates[idx]);
            find(idx,target-candidates[idx],candidates,ans,diary);
            diary.pop_back();
        }

        //not pick the element
        find(idx+1,target,candidates,ans,diary);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>diary;
        find(0,target,candidates,ans,diary);

        return ans;
        
    }
};